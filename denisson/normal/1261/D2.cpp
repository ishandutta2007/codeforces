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

const int mod = 998244353;

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



int n, k;
int a[200007];

int fac[200007];
int ifac[200007];

int cnk(int n, int k) {
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 200007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 200007; ++i) ifac[i] = bp(fac[i], mod - 2);

  cin >> n >> k;
  readArr(a, a + n);

  if (n == 1 || k == 1) cout << 0, exit(0);

  int cnt_fin = 0, cnt_now = 0;

  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;

    if (a[i] == a[j]) {
      cnt_fin++;
    }  else {
      cnt_now++;
    }
  }


  int res = 0;

 /// per(cnt_now, cnt_fin);

  for (int now = 0; now <= cnt_now; ++now) {
    int heh = mult(bp(k - 2, now), cnk(cnt_now, now));

    

    int f = cnt_now - now;
    int cc = bp(2, f);

 //   pper(cc);
  //  pper(cnk(f, f >> 1));


    if (f % 2 == 0) dec(cc, cnk(f, f >> 1));


 //   pper(cc);

    cc = mult(cc, bp(2, mod - 2));


  //  per("====", now, heh, f, cc);

    heh = mult(heh, cc);

    add(res, heh);

    if (k == 2) break;

  }


  cout << mult(res, bp(k, cnt_fin));

}