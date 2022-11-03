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
string s;

int K = 1<<20;

// u can set modular arithmetic here
void hadamard(vector<int>& v){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                int F = v[start+w];
                add(F, v[start+step/2+w]);
                int S = v[start+w];
                dec(S, v[start+step/2+w]);
                v[start + w] = F;
                v[start+step/2+w] = S;
            }
        }
    }
}

/* Usage Example
    vector<int> f(K), g(K);
    hadamard(f);
    hadamard(g);
    for (int i=0; i < K; i++) f[i] *= g[i];
    hadamard(f);
    for (int i=0; i < K; i++) f[i] /= K;
    // f is ur answer
*/

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> s;

  int res = 0;

  vector<int> f1(1 << n);
  vector<int> f2(1 << n);

  for (int m1 = 0; m1 < (1 << n); ++m1) if (s[m1] == '1') f1[m1] = 1;
  for (int m2 = 0; m2 < (1 << n); ++m2) if (s[m2] == '0') f2[m2] = 1;

  K = 1 << n;

  hadamard(f1);
  hadamard(f2);


  for (int i = 0; i < f1.size(); ++i) f1[i] = mult(f1[i], f2[i]);


  hadamard(f1);


  auto KEK = bp(K, mod - 2);
  for (int i = 0; i < f1.size(); ++i) f1[i] = mult (f1[i], KEK);

  for (int m1 = 0; m1 < (1 << n); ++m1) add(res, mult(f1[m1], 1 << __builtin_popcount(m1)));

/*

  for (int m2 = 0; m2 < (1 << n); ++m2) if (s[m1] == '1' && s[m2] == '0') {
    res += 1 << __builtin_popcount(m1 ^ m2);

   // per (m1, m2, 1 << __builtin_popcount(m1 ^ m2));
  }

 // pper(res);

 */

  cout << mult(res, 3); // * 3;
}