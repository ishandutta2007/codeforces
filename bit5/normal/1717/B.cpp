#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7;
int n, K, r, c;
char ans[507][507];
inline void work() {
	n=read(), K=read(), r=read()-1, c=read()-1;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) ans[i][j]='.';
	r%=K, c%=K;
	for (int i=0, j=0; i<K; i++) {
		if (i==r) continue;
		if (j==c) j++;
		for (int x=i; x<n; x+=K)
			for (int y=j; y<n; y+=K) ans[x][y]='X';
		j++;
	}
	for (int x=r; x<n; x+=K)
		for (int y=c; y<n; y+=K) ans[x][y]='X';
	for (int i=0; i<n; i++, putchar(10))
		for (int j=0; j<n; j++) putchar(ans[i][j]);
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}