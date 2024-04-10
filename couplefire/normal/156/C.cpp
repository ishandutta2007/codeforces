#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<r;++i)
using namespace std;
 
const int MAXN = 110, MAXK = 3000, A = 26, D = 1e9+7;
int f[MAXN][MAXK], T;
char s[MAXN];
 
int main() {
	f[0][0] = 1;
	rep(i, 1, MAXN) rep(j, 0, MAXK) rep(k, 0, A)
		f[i][j] = (f[i][j]+(j-k>=0?f[i-1][j-k]:0))%D;
	cin>>T;
	for(int n,k; T--&&cin>>s;) {
		n = strlen(s), k = 0;
		rep(i, 0, n) k += s[i]-'a';
		cout<<f[n][k]-1<<'\n';
	}
}