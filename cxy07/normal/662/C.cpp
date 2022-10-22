//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define LL long long
#define pii pair<int,int>
//#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = (1 << 20) + 10;
const int INF = 2e9;
const int G = 3;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;

int n,m,ans = INF;
int a[MAXN],b[MAXN],popcount[MAXN];
char mp[21][(int)1e5 + 10];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void FWT(int *s,int opt) {
	for(int mid = 1;mid < (1 << n); mid <<= 1) 
		for(int i = 0;i < (1 << n); i += (mid << 1)) 
			for(int j = 0;j < mid; ++j) {
				int x = s[i + j],y = s[i + j + mid];
				s[i + j] = x + y;
				s[i + j + mid] = x - y;
				if(opt == -1) s[i + j] >>= 1,s[i + j + mid] >>= 1;
			}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	for(int i = 1;i <= n; ++i) scanf("%s",mp[i] + 1);
	for(int i = 1;i <= m; ++i) {
		int state = 0;
		for(int j = 1;j <= n; ++j) {
			state <<= 1;
			state |= (bool)(mp[j][i] == '1');
		}
		a[state]++;
	}
	for(int i = 0;i <= (1 << n); ++i)
		popcount[i] = popcount[i >> 1] + (i & 1);
	for(int i = 0;i < (1 << n); ++i)
		b[i] = min(popcount[i],n - popcount[i]);
	FWT(a,1);
	FWT(b,1);
	for(int i = 0;i < (1 << n); ++i) a[i] *= b[i];
	FWT(a,-1);
	for(int i = 0;i < (1 << n); ++i) ans = min(ans,a[i]);
	printf("%lld\n",ans);
	return 0;
}