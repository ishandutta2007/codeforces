#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define rep(i,j,k) for(register int i = j; i <= k; i++)
#define dow(i,j,k) for(register int i = j; i >= k; i--)
#define ll long long
using namespace std;
 
inline int read() { 
	int s = 0, t = 1; char c = getchar();
	while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
	while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
	return s * t;
}
 
const int N = 1e3+5, BIT = 10; const ll inf = 1e16;
int f[N][N][BIT][BIT], Log[N] = {-1};
inline int check(int x1,int y1,int x2,int y2) { 
	int t1 = Log[x2-x1+1], t2 = Log[y2-y1+1];
	return max(max(f[x1][y1][t1][t2],f[x1][y2-(1<<t2)+1][t1][t2]),max(f[x2-(1<<t1)+1][y1][t1][t2],f[x2-(1<<t1)+1][y2-(1<<t2)+1][t1][t2]));
}
 
int main() { 
//	freopen("in.txt","r",stdin);
	int n = read(), m = read(), x;
	rep(i,1,n) { 
		rep(j,1,m) { 
			x = read();
			if( x ) f[i][j][0][0] = min(f[i-1][j][0][0],min(f[i-1][j-1][0][0],f[i][j-1][0][0])) + 1;
		}
	} 
	rep(i,1,max(n,m)) Log[i] = Log[i>>1] + 1;
	rep(i,1,Log[n]) { 
		rep(k,1,n-(1<<i)+1) { 
			rep(l,1,m) { 
				f[k][l][i][0] = max(f[k][l][i-1][0],f[k+(1<<i-1)][l][i-1][0]);
			}
		}
	} 
	rep(i,0,Log[n]) { 
		rep(j,1,Log[m]) { 
			rep(k,1,n-(1<<i)+1) { 
				rep(l,1,m-(1<<j)+1) { 
					f[k][l][i][j] = max(f[k][l][i][j-1],f[k][l+(1<<j-1)][i][j-1]);
				}
			}
		}
	}
	int q = read();
	while( q-- ) { 
		int x1 = read(), y1 = read(), x2 = read(), y2 = read(), l = 0, r = min(x2-x1+1,y2-y1+1), mid;
		while( l < r ) { 
			mid = (l + r + 1) >> 1;
			if( check(x1+mid-1,y1+mid-1,x2,y2) >= mid ) l = mid;
			else r = mid - 1;
		}  
		printf("%d\n",l);
	}
//	n = read();
	return 0;
}