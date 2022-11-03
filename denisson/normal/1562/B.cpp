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

int cnt[11];
bool is_pr[100007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  is_pr[1] = 1;
  for (int i = 2; i < 100007; ++i) if (!is_pr[i]) {
    for (int j = 2 * i; j < 100007; j += i) is_pr[j] = 1;
  }

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s >> s;
    string res;

    fill(cnt, cnt + 11, 0);
    for (char c : s) cnt[c - '0']++;


    for (char c : s) {
      if (c != '2' && c != '3' && c != '5' && c != '7') {
        res += c;
        break;
      }
    }

    if (res.size() == 0) {
      if (cnt[2] > 1) {
        res = "22";
      } else if (cnt[3] > 1) {
        res = "33";
      } else if (cnt[5] > 1) {
        res = "55";
      } else if (cnt[7] > 1) {
        res = "77";
      } else {
        for (int mask = 1; mask < (1 << s.size()); ++mask) {
          int val = 0;
          string gg;
          for (int i = 0; i < s.size(); ++i) if ((mask >> i) & 1) val = val * 10 + s[i] - '0', gg += s[i];
          if (is_pr[val]) {
            if (res.size() == 0 || res.size() > gg.size()) {
              res = gg;
            }
          }
        }
      }
    }

    cout << res.size() << '\n' << res << '\n';
  }

}