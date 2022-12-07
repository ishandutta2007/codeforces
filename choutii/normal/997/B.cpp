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

int n, cnt[233], a[4] = {1, 5, 10, 50}, f[5333][5333];
int main() {
  cin >> n;
  f[0][0] = 1;
  int tn = 13;
  for (int p = 1; p <= tn; p++) {
    for (int i = 1; i <= tn * 50; i++) {
      for (int k = 0; k < 4; k++)
        if(a[k] <= i) {
          f[p][i] |= f[p - 1][i - a[k]];
        }
      cnt[p] += !!f[p][i];
    }
  }
    
  if(n <= tn)
    cout << cnt[n] << "\n";
  else
    cout << (LL) (n - tn) * 49 + cnt[tn];

	return 0;
}