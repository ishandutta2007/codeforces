//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 210;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T,n,m;
int a[MAXN][MAXN];
char s[MAXN];
vector<pii> ans;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n);
		ans.clear();
		for(int i = 1;i <= n; ++i) {
			scanf("%s",s + 1);
			for(int j = 1;j <= n; ++j) {
				if(s[j] == 'S' || s[j] == 'F') {a[i][j] = -1; continue;}
				a[i][j] = s[j] - '0';
			}
		}
		for(int i = 0,j;i <= 1; ++i) {
			j = i ^ 1;
			ans.clear();
			if(a[1][2] != i) ans.pb(mp(1,2));
			if(a[2][1] != i) ans.pb(mp(2,1));
			if(a[n][n - 1] != j) ans.pb(mp(n,n - 1));
			if(a[n - 1][n] != j) ans.pb(mp(n - 1,n));
			if(ans.size() <= 2) break;
		}
		cout << ans.size() << endl;
		for(int i = 0;i < ans.size(); ++i)
			cout << ans[i].fst << ' ' << ans[i].scd << endl;
	}
	return 0;
}