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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

int n,m,now,cnt;
int is[MAXN][2];
int a[MAXN];
bool maybe[MAXN];

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
	read(n); read(m);
	for(int i = 1;i <= n; ++i) {
		read(a[i]);
		if(a[i] > 0) is[a[i]][1]++;	
		else is[-a[i]][0]++;
	}
	for(int i = 1;i <= n; ++i) now += is[i][0];
	for(int i = 1;i <= n; ++i) {
		now -= is[i - 1][1]; now += is[i - 1][0];
		now -= is[i][0]; now += is[i][1];
		if(now == m) maybe[i] = true,cnt++;
	}
	//cout << cnt << endl;
	for(int i = 1;i <= n; ++i) {
		if(!maybe[abs(a[i])]) {
			if(a[i] < 0) puts("Truth");
			else puts("Lie");
		} else {
			if(cnt == 1) puts(a[i] < 0 ? "Lie" : "Truth");
			else puts("Not defined");
		}
	}
	return 0;
}