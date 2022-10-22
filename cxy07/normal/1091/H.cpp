#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")

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
#define vec vector

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, d, ans;
int pr[MAXN], cnt;
int sg[MAXN];
bool np[MAXN];
bitset<MAXN> S[110], trans;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void sieve(int x) {
	for(int i = 2; i <= x; ++i) {
		if(!np[i]) pr[++cnt] = i;
		for(int j = 1; j <= cnt && pr[j] * i <= x; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	sieve(2e5); 
	read(n); read(d);
	for(int i = 1; i <= cnt; ++i) trans[pr[i]] = 1;
	for(int i = 1; i <= cnt; ++i) 
		for(int j = i; j <= cnt && 1ll * pr[i] * pr[j] <= (LL)2e5; ++j)
			trans[pr[i] * pr[j]] = 1;
	trans[d] = 0; S[0] = trans;
	for(int i = 1; i <= (int) 2e5; ++i) {
		while(S[sg[i]][i]) sg[i]++;
		S[sg[i]] |= (trans << i);
	}
	for(int i = 1, a, b, c; i <= n; ++i) {
		read(a); read(b); read(c);
		ans ^= sg[b - a - 1];
		ans ^= sg[c - b - 1];
	} 
	if(ans) puts("Alice\nBob");
	else puts("Bob\nAlice");
	return 0;
}