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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T,n,m,k;
char s[MAXN];
bool flag = false;

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
		read(n); read(k);
		flag = true;
		scanf("%s",s + 1);
		for(int i = 1;i <= k; ++i) {
			char now = '?';
			for(int j = i;j <= n;j += k)
				if(s[j] != '?') now = s[j];
			if(now == '?') continue;
			for(int j = i;j <= n;j += k) {
				if(s[j] != '?' && s[j] != now) {
					flag = false;
					break;
				}
			}
			if(!flag) break;
			for(int j = i;j <= n;j += k) s[j] = now;
		}
		if(!flag) {
			puts("NO");
			continue;
		}
		int cnt[2] = {0,0},emp = 0;
		for(int i = 1;i <= k; ++i) {
			if(s[i] != '?') cnt[s[i] - '0']++;
			else emp++;
		}
		if(abs(cnt[0] - cnt[1]) <= emp) puts("YES");
		else puts("NO");
	}
	return 0;
}