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

const int NX = 301234;

int n, x, y;
char s[NX];

int main() {
  read(n); read(x); read(y);
  scanf("%s", s + 1);
  s[0] = '1';
  LL ans = 0;
  for (int i = 1; i <= n; i++)
    ans += (s[i] == '0' && s[i - 1] == '1');
	LL t = ans;
  ans *= y;
	if(t)
	 cmin(ans, (t - 1) * x + y);
	 cout << ans << "\n";
  return 0;
}