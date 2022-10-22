//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

int n,m,ans,tot;
int s[2][MAXN];
vector<int> a;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void solve(vector<int> &v,int len,int dep) {
	if(len <= 1 || dep < 0) return;
	vector<int> l,r;
	l.clear(),r.clear();
	int cnt[2] = {0,0},ll[2] = {0,0};
	for(int i = len - 1;~i; --i) {
		if((v[i] & (1 << dep))) s[1][dep] += cnt[0];
		else s[0][dep] += cnt[1];
		cnt[((v[i] & (1 << dep)) ? 1 : 0)]++;
	}
	for(int i = 0;i < len; ++i) {
		if(v[i] & (1 << dep)) r.push_back(v[i]),ll[1]++;
		else l.push_back(v[i]),ll[0]++;
	}
	solve(l,ll[0],dep - 1);
	solve(r,ll[1],dep - 1);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1,x;i <= n; ++i) {
		read(x);
		a.push_back(x);
	}
	solve(a,n,31);
	for(int i = 31;~i; --i) {
		if(s[0][i] < s[1][i]) ans |= (1 << i);
		tot += min(s[0][i],s[1][i]);
	}
	printf("%lld %lld\n",tot,ans);
	return 0;
}