#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}


int n, m;
pair<int, int> a[200007];
ll ans[200007];

ll rem[33];
ll cnt[33];
set<pair<ll, int> > se[33];

int getV(int x) {
  int v = 0;
  for (int i = 0; i < 30; ++i) if ((x >> i) & 1) v = i;
  return v;
}

void up() {
  for (int j = 0; j < 30; ++j) {

    while (se[j].size()) {
      auto now = *se[j].begin();

      //pper(now);
      //pper(rem[j]);
      //pper(j);

      if (now.x - rem[j] < ((ll)1 << j)) {
        ans[now.y] += cnt[j];

        if (now.x - rem[j] > 0) {
          int v = getV(now.x - rem[j]);
          ans[now.y] -= cnt[v];
          se[v].insert(mp(now.x - rem[j] + rem[v], now.y));
        } // else if (now.x - rem[j] < 0) --ans[now.y];

        se[j].erase(now);

      } else break;
    }

  }
}

int main() {
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a + 1, a + n + 1);

  sort(a + 1, a + n + 1, [](pair<int, int> a, pair<int, int> b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
  });

  //for (int i = 1; i <= n; ++i) {
  //  pper(a[i]);
  //}



  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    se[getV(x)].insert(mp(x, i));
  }

  for (int i = 1; i <= n; ++i) {

    int x = a[i].x;
    int fr = 1;

    for (int j = 0; j < 30; ++j) {

      if ((1 << (j + 1)) - 1 >= x) {

        if (fr) {
          while (se[j].size()) {
            auto now = *prev(se[j].end());

            // per(now, rem[j], x, cnt[j], ans[now.y]);

            if (now.x - rem[j] - x >= 0) {

              ans[now.y] += cnt[j] + 1;

              if (now.x - rem[j] - x > 0) {
                int v = getV(now.x - rem[j] - x);
                ans[now.y] -= cnt[v];
                se[v].insert(mp(now.x - rem[j] - x + rem[v], now.y));
              }

              se[j].erase(now);

            } else break;

          }
        } else {
          rem[j] += x;
          ++cnt[j];
        }

        fr = 0;

      }

    }

    up();
  }


  for (int j = 0; j < 30; ++j) {
    for (auto [w1, w2] : se[j]) ans[w2] += cnt[j];
  }

  for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
}