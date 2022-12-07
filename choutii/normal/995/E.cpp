#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
#define debug(x) cerr << #x" = " << x << endl

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T, typename TT> ostream & operator << (ostream &out, pair<T, TT> t) { return out << "(" << t.X << "," << t.Y << ")";}
template <typename T> ostream & operator << (ostream &out,vector<T> t) { out << "["; for (auto x:t) out << x << " "; out << "]"; return out;}
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

int u, v, mod;
int exp(int a, int n) {
  int res = 1;
  for (; n; n >>= 1) {
    if (n & 1) 
      res = (LL) res * a % mod;
    a = (LL) a * a % mod;
  }
  return res;
}

int mod_inv(int x) {
  return exp(x, mod - 2);
}

const int l = 100, NX = 40000;

VI path[NX];
map<int, int> h;

int main() {
  read(u); read(v); read(mod);
  int half = sqrt(mod) + 1; 
  for (int i = 0; i <= half; i++) {
    int t = u;
    for(int p = 0; p < l; p++) {
      int x = rand() % 3 + 1;
      path[i].pb(x);
      if (x == 1)
        t = (t + 1) % mod;
      if (x == 2)
        t = (t + mod - 1) % mod;
      if (x == 3)
        t = mod_inv(t);
    }
    h[t] = i;        
  } 
  
  while (true) {
    VI cur;
    int t = v;
    for (int i = 0; i < l; i++) {
      int x = rand() % 3 + 1;
      cur.pb(x);
      if(x == 1)
        t = (t + mod - 1) % mod;
      if(x == 2)
        t = (t + 1) % mod;
      if(x == 3)
        t = mod_inv(t);
    }
    if(h.find(t) != h.end()) {
      int u = h[t];
      for (int i = l - 1; ~i; i--)
        cur.pb(path[u][i]);
      reverse(ALL(cur));
      
      printf("%d\n", l * 2);
      for (int i : cur)
        printf("%d ", i);
      return 0;
    }
  }
	return 0;
}