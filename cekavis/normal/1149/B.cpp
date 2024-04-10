#include<bits/stdc++.h>
using namespace std;
const int N = 100005, M = 252, C = 26, K = 3;
int n, q, len[K], a[N][C], f[M][M][M];
char t[K][M], s[N];
int main() {
	scanf("%d%d%s", &n, &q, s+1), fill(a[n+1], a[n+1]+C, n+1), fill(a[n+2], a[n+2]+C, n+1);
	for(int i=n; i; --i) memcpy(a[i], a[i+1], C<<2), a[i][s[i]-'a']=i;
	while(q--){
		char opt, id;
		while(isspace(opt=getchar()));
		while(isspace(id=getchar()));
		id-='1';
		if(opt=='+'){
			while(isspace(opt=getchar()));
			opt-='a', t[id][++len[id]]=opt;
			if(!id)
				for(int i=0; i<=len[1]; ++i) for(int j=0; j<=len[2]; ++j)
					f[len[0]][i][j]=min(min(a[f[len[0]-1][i][j]+1][opt], a[i?f[len[0]][i-1][j]+1:n+1][t[1][i]]), a[j?f[len[0]][i][j-1]+1:n+1][t[2][j]]);
			else if(id==1)
				for(int i=0; i<=len[0]; ++i) for(int j=0; j<=len[2]; ++j)
					f[i][len[1]][j]=min(min(a[f[i][len[1]-1][j]+1][opt], a[i?f[i-1][len[1]][j]+1:n+1][t[0][i]]), a[j?f[i][len[1]][j-1]+1:n+1][t[2][j]]);
			else
				for(int i=0; i<=len[0]; ++i) for(int j=0; j<=len[1]; ++j)
					f[i][j][len[2]]=min(min(a[f[i][j][len[2]-1]+1][opt], a[i?f[i-1][j][len[2]]+1:n+1][t[0][i]]), a[j?f[i][j-1][len[2]]+1:n+1][t[1][j]]);
		}
		else --len[id];
		puts(f[len[0]][len[1]][len[2]]<=n?"YES":"NO");
	}
	return 0;
}