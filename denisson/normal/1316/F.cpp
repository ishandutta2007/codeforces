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

#define pper(a) cout << #a << " = " << a << endl;

void per() { cout << endl; }
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

int n, k;
int a[300007];
pair<int, int> f[300007];
int step[600007];

struct Tree {
    int t[600007 * 4];
    int le[600007 * 4];
    int ri[600007 * 4];
    int cnt[600007 * 4];
    
    void up(int v, int vl, int vr, int pos, int val, int addd) {
        if (vl == vr) {
            cnt[v] += addd;
            t[v] = 0;
            le[v] = mult(step[1], val);
            ri[v] = mult(step[1], val);
        //    cout <<le[v] << ' ' << ri[v] << ' ' << val << endl;
        } else {
            int vm = (vl + vr) >> 1;
            if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val, addd);
            else up(v * 2 + 2, vm + 1, vr, pos, val, addd);
            
            cnt[v] = cnt[v * 2 + 1] + cnt[v * 2 + 2];
            
          //  cout << le[v * 2 + 1] << ' ' << ri[v * 2 + 2] << endl;
            
            t[v] = t[v * 2 + 1];
            add(t[v], t[v * 2 + 2]);
            add(t[v], mult(le[v * 2 + 1], ri[v * 2 + 2]));
            
            le[v] = le[v * 2 + 2];
            add(le[v], mult(le[v * 2 + 1], step[cnt[v * 2 + 2]]));
            ri[v] = ri[v * 2 + 1];
            add(ri[v], mult(ri[v * 2 + 2], step[cnt[v * 2 + 1]]));
            
        }
    }
} tr;

int pp[300007];

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int rev = bp(2, mod - 2);
  step[0] = 1;
  for (int i = 1; i < 600007; ++i) step[i] = mult(step[i - 1], rev);
  
  cin >> n;
  readArr(a, a + n);
  cin >> k;
  readArr(f, f + k);
  
  map<int, int> was;
  for (int i = 0; i < n; ++i) was[a[i]]++;
  for (int i = 0; i < k; ++i) was[f[i].y]++;
  
  int d = 0;
  vector<pair<int, int> > p;
  for (auto [w1, w2] : was) p.pb(mp(w1, w2));
  for (auto [w1, w2] : p) {
      was[w1] += d;
      d += w2;
  }
  
  for (int i = 0; i < n; ++i) {
    int pos = was[a[i]]--;
    tr.up(0, 0, d, pos, a[i], 1);
    pp[i] = pos;
  }
  
  cout << tr.t[0] << "\n";
  
  for (int i = 0; i < k; ++i) {
      int v = f[i].x - 1;
      int val = f[i].y;
      int pos = was[val]--;
      
      tr.up(0, 0, d, pp[v], 0, -1);
      
 // cout << tr.t[0] << "\n";
      
      pp[v] = pos;
      a[v] = val;
      tr.up(0, 0, d, pos, a[v], 1);
      
  cout << tr.t[0] << "\n";
  }
  
  
    
  

}