#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define db double
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

const int N = 3007;

int dp[N][N];
int res[N][N];
int last[N];

vector<int> restore(vector<int> v) {
    vector<int> t;
    int cur = 0;
    
    while (cur < v.size()) {
        int f = cur;
        while (f < v.size() && v[cur] == v[f])f++;
        t.pb(v[cur]);
        cur = f;
    }
    return t;
}

bool cmp(pair<int, int>a, pair<int,int> b) {
    int l1 = a.y - a.x;
    int l2 = b.y - b.x;
    return (l1 < l2);
}

vector<int> vals[N];

void solve() {
    
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto &x : v) {
        cin >> x;
        --x;
    }
    
    for(int i = 0;i < n;++i) {
        vals[i].clear();
    }

    
    v = restore(v);
    n = v.size();
    
    for (int i = 0;i < n; ++i) {
        vals[v[i]].pb(i);
    }
    
    vector<pair<int, int> > segments;
    segments.pb(mp(-1, n));
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (v[i] == v[j]) segments.pb(mp(i, j));
        }
    }
    
    sort(all(segments),cmp);
    
    for (int i = 0;i < n; ++i) last[i] = i;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0;
            res[i][j] = 0;
        }
    }
    
    for (auto x : segments) {
        int start = x.x + 1;
        for (int i = last[start]; i < x.y; ++i) {
            if (i - 1 >= 0) dp[start][i] = dp[start][i-1];
            int T = v[i];
            for (auto to : vals[T]) {
                if (to < i && to >= start) {
                    //per(x,i,to);
                    dp[start][i] = max(dp[start][i], dp[start][to] + res[to][i]);
                }
            }
        }
        
        last[start] = x.y;
        
        int tut = dp[start][x.y - 1];
        
       // per(x.x, x.y);
        
        if (start != 0) {
            res[x.x][x.y] = tut + 1;
        }
        else {
        //    per(res[2][3]);
            cout<< n - 1 - tut << '\n';
            return;
        }
        
    }

    
    
    
}
 
int main(){
#ifdef LOCAL
  freopen("M_input.txt", "r", stdin);
  //freopen("M_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int t;
  cin >> t;
  
  for (int i = 0; i < t; ++i) solve();
 
 
}