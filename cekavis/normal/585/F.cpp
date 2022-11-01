#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005, K = 52, M = N*K/2, C = 10, P = 1000000007;
int n, d, r, ans, cnt, q[M], fail[M], ch[M][C], f[K][M];
bool g[M];
char x[K], y[K], s[N];
int main() {
	scanf("%s%s%s", s+1, x+1, y+1), n=strlen(s+1), d=strlen(x+1);
	cnt=1;
	for(int i=1; i<=n-d/2+1; ++i){
		int x=1;
		for(int j=i; j<i+d/2; ++j){
			int &t=ch[x][s[j]-'0'];
			x=t?t:t=++cnt;
		}
		g[x]=1;
		for(int j=0; j<C; ++j) ch[x][j]=x;
	}
	for(int i=0; i<C; ++i) if(ch[1][i]) fail[q[++r]=ch[1][i]]=1; else ch[1][i]=1;
	for(int l=1; l<=r; ++l){
		int x=q[l];
		if(!g[x]) for(int j=0; j<C; ++j)
			if(!ch[x][j]) ch[x][j]=ch[fail[x]][j];
			else fail[q[++r]=ch[x][j]]=ch[fail[x]][j];
	}
	bool o=0;
	int xx=1, yy=1;
	for(int i=1; i<=d; ++i){
		x[i]-='0', y[i]-='0';
		if(o){
			for(int j=x[i]+1; j<C; ++j)
				++f[i][ch[xx][j]];
			for(int j=y[i]-1; ~j; --j)
				++f[i][ch[yy][j]];
		}
		else if(o|=x[i]!=y[i]) for(int j=x[i]+1; j<y[i]; ++j) ++f[i][ch[xx][j]];
		xx=ch[xx][x[i]], yy=ch[yy][y[i]];
	}
	++f[d][xx], f[d][yy]+=o;
	for(int i=1; i<d; ++i) for(int j=1; j<=cnt; ++j) for(int k=0; k<C; ++k)
		(f[i+1][ch[j][k]]+=f[i][j])%=P;
	for(int i=1; i<=cnt; ++i) if(g[i]) (ans+=f[d][i])%=P;
	printf("%d\n", ans);
	return 0;
}