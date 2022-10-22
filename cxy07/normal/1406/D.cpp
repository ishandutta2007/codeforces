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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,q;
int a[MAXN];
int s[MAXN],sum;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int solve(int x) {
	return (x >= 0 ? (x + 1) / 2 : x / 2);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1;i <= n; ++i) read(a[i]);
	for(int i = 2;i <= n; ++i) {
		s[i] = a[i] - a[i - 1];
		if(s[i] > 0) sum += s[i];
	}
	printf("%lld\n",solve(sum + a[1]));
	read(q);
	while(q--) {
		int l,r,x;
		read(l); read(r); read(x);
		if(l == 1) a[1] += x;
		if(l != 1) {
			if(s[l] > 0) sum -= s[l];
			s[l] += x;
			if(s[l] > 0) sum += s[l];
		}
		if(r != n) {
			if(s[r + 1] > 0) sum -= s[r + 1];
			s[r + 1] -= x;
			if(s[r + 1] > 0) sum += s[r + 1];
		}
		printf("%lld\n",solve(sum + a[1]));
	}
	return 0;
}