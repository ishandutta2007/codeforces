//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = 6010;
const int INF = 2e9;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

int n,m,ans = INF;
char s[MAXN],t[MAXN];

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
	scanf("%s%s",s + 1,t + 1);
	n = strlen(s + 1),m = strlen(t + 1);
	for(int i = 1;i <= n; ++i) {
		s[i + 2000] = s[i];
		s[i] = s[i + n + 2000] = '~';
	}
	//for(int i = 1;i <= 3 * n; ++i) cout << s[i];
	//cout << endl;
	for(int i = 1;i <= 4000; ++i) {
		int tmp = 0;
		for(int j = 1;j <= m; ++j) 
			if(s[i + j - 1] != t[j]) tmp++;
		ans = min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}