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

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n;
int a[1000007];

int cnt[7];
int f[7];


int gg() {
  copy(cnt, cnt + 7, f);

  if ((*min_element(f, f + 7)) < 0) return 1e9;

  int res = 0;

  f[0] += f[3] + f[6];
  f[1] += f[4];
  f[2] += f[5];

  res += 0 * f[3] + f[4] + f[5] + 1 * f[6];

  if (f[1] > f[2]) {
    res += f[2] + 2 * (f[1] - f[2]) / 3;
  }  else {
    res += f[1] + 3 * (f[2] - f[1]) / 3;
  }   
  return res;
}

void solve() {

  fill(cnt, cnt + 7, 0);

  cin >> n;
  readArr(a, a + n);
  for (int i = 0; i < n; ++i) --a[i];

  int res = 0;

  vector<int> was(n, 0);
  for (int i = 0; i < n; ++i) if (!was[i]) {
    int v = i;
    int cc = 0;
    while (!was[v]) {
      was[v] = 1;
      ++cc;
      v = a[v];
    }

    while (cc >= 7) cc -= 3, ++res;

    cnt[cc]++;
  }

  int now = 1e9;

 // for (int i = 0; i < 7; ++i) per(i, cnt[i]);

  if (n % 3 == 0) {

    now = gg();

  } else if (n % 3 == 2) {

    for (int i = 2; i <= 6; ++i) {
      --cnt[i]; ++cnt[i - 2];
      now = min(now, gg() + (i != 2));
      ++cnt[i]; --cnt[i - 2];
    }

    cnt[1] -= 2;
    now = min(now, gg() + 1);

  } else {

    for (int i1 = 1; i1 <= 6; ++i1) {
      for (int i2 = 1; i2 <= 6; ++i2) {

        if (i1 == 1) {
          cnt[i1] -= 2;
        } else {
          cnt[i1]--; ++cnt[i1 - 2];
        }

        if (i2 == 1) {
          cnt[i2] -= 2;
        } else {
          cnt[i2]--; ++cnt[i2 - 2];
        }

        now = min(now, gg() + (i1 != 2) + (i2 != 2));

        if (i1 == 1) {
          cnt[i1] += 2;
        } else {
          cnt[i1]++; --cnt[i1 - 2];
        }

        if (i2 == 1) {
          cnt[i2] += 2;
        } else {
          cnt[i2]++; --cnt[i2 - 2];
        }

      }
    }



    for (int i = 4; i <= 6; ++i) {
      --cnt[i]; ++cnt[i - 4];
      now = min(now, gg() + (i != 4));
      ++cnt[i]; --cnt[i - 4];
    }


    cnt[1] -= 4;
    uin(now, gg() + 3);
    cnt[1] += 4;

    cnt[1] -= 2; cnt[2] -= 1;
    uin(now, gg() + 2);
    cnt[1] += 2; cnt[2] += 1;




    for (int i1 = 1; i1 <= 3; ++i1) {
      for (int i2 = 1; i2 <= 3; ++i2) if (i1 + i2 >= 4) {
        cnt[i1]--; cnt[i2]--; cnt[i1 + i2 - 4]++;
        uin(now, gg() + 1 + (i1 + i2 != 4));
        cnt[i1]++; cnt[i2]++; cnt[i1 + i2 - 4]--;
      } 
    }
  }

  int RES1 = 1;
  int kek = n;
  while (n > 0) {
    if (n % 3 != 0) {
      RES1 = mult(RES1, 2);
      n -= 2;
    } else {
      RES1 = mult(RES1, 3);
      n -= 3;
    }
  }

  cout << RES1 << ' ' << res + now << "\n";

}



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}