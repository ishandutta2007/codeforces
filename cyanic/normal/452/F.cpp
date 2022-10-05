#include<cstdio>
#include<cstring>
#include<algorithm>
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l+r) >> 1)
#define len (((l+r) >> 1)-l+1)
using namespace std;
 
const int maxn = 300009;
const int seed = 23333;
const int MOD = 998244353;
int L[maxn<<2], R[maxn<<2], pow[maxn];
int n, a, b;
 
inline int read(){
	char ch = getchar(); int x = 0;
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') { x = x*10+ch-'0'; ch = getchar(); }
	return x;
}
 
inline void init(){
	pow[0] = 1;
	for (int i=1; i<=n; i++)
		pow[i] = 1LL*pow[i-1]*seed%MOD;
}
 
void update(int T[], int o, int l, int r, int x){
	if (l == r) { T[o] = 1; return; }
	if (x <= len) update(T, lc, l, mid, x);
	else update(T, rc, mid+1, r, x-len);
	T[o] = (1LL*T[rc]*pow[len] + T[lc]) % MOD;
}
 
int query(int T[], int o, int l, int r, int x, int y){
	if (x > y) return 0; if (y-x == r-l) return T[o];
	if (y <= len) return query(T, lc, l, mid, x, y);
	if (len+1 <= x) return query(T, rc, mid+1, r, x-len, y-len);
	return (query(T, lc, l, mid, x, len) 
			+1LL*query(T, rc, mid+1, r, 1, y-len)
			*pow[len-x+1]) % MOD;
}
 
int main(){
	n = read(); init();
	for (int i=1; i<=n; i++){
		a = read(); b = min(a-1, n-a);
		if (query(L, 1, 1, n, a-b, a-1) != query(R, 1, 1, n, n-(a+b)+1, n-(a+1)+1)){
			puts("YES"); return 0;
		}
		update(L, 1, 1, n, a); update(R, 1, 1, n, n-a+1);
	}
	puts("NO");
	return 0;
}