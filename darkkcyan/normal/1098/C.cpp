#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

// the tree is 0-indexed
#define maxn 101010
int n;
llong s;
llong getMaxS(llong branch) {
  vector<int> td(1, 1);
  llong ts = 1;
  rep1(i, n - 1) { 
    td.push_back(td[(i - 1) / branch] + 1);
    ts += td.back();
  }
  return ts;
}

int p[maxn], d[maxn];
bool ismain[maxn];
void build(int branch) {
  ismain[0] = 1;
  d[0] = 1;
  rep1(i, n - 1) {
    p[i] = (i - 1) / branch;
    d[i] = d[p[i]] + 1;
  }
  for (llong i = n - 1; i != 0; i = p[i]) ismain[i] = 1;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> s;
  if (n == 1) {
    if (s != 1) cout << "NO"; else cout << "YES\n";
    return 0;
  }

  if ((llong) n * (n + 1) / 2 < s) {
    cout << "NO";
    return 0;
  }

  int l = 1, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (getMaxS(mid) <= s) r = mid;
    else l = mid + 1;
  }
  if (l == n) {
    cout << "NO";
    return 0;
  }

  //clog << "OK" << ' ' << l << ' ' << getMaxS(l) << endl;

  s -= getMaxS(l);
  build(l);

  int last = n - 1;
  for (int i = n - 1; i >= 0 and s; --i) {
    if (ismain[i]) continue;
    if (s >= d[last] + 1 - d[i]) {
      s -= d[last] + 1 - d[i];
      d[i] = d[last] + 1;
      p[i] = last;
      last = i;
      ismain[i] = 1;
    } else {
      for (int f = n - 1; f >= 0; --f) {
        if (f == i) continue;
        if (d[f] + 1 - d[i] != s) continue;
        p[i] = f;
        break;
      }
      s = 0;
    }
  }

  cout << "YES\n";
  rep1(i, n - 1) cout << p[i] + 1 << ' ';

  return 0;
}