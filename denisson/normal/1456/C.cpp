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

ll n, k;
ll a[500007];


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;
  readArr(a, a + n);

  vector<ll> w1, w2;

  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0) w1.pb(a[i]); else w2.pb(a[i]);
  }

  sort(all(w1));
  reverse(all(w1));


  ll RES = -5e18;

  ll add = 0;
  ll tot = 0;

  for (ll x : w1) {
    add += tot;
    tot += x;
  }


  w2.pb(tot);
  sort(all(w2));
  reverse(all(w2));

  ll SU = 0;
  ll func = 0;
  for (ll x : w2) {
    func += SU;
    SU += x;
  }

  uax(RES, func);

  if (k > 0) {

    
    ll new_pos = 0;
    ll cur_pos = 0;
    ll can = k + 1;

    for (int i = (int)w2.size() - 1; i > 0; --i) {
      if (can == k + 1) {
        SU -= w2[i];
        --can;
        ++cur_pos;
      } else {
        
        SU -= w2[i];
        func -= SU;
        func -= w2[i] * cur_pos;

        func += new_pos * (ll)w2[i];

        uax(RES, func);

        --can;
        if (can == 0) {
          can = k + 1;
          new_pos++;
        }
      }
    }

  }

  cout << RES + add;
}