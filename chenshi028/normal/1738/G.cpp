#include<cstdio>
using namespace std;
const int o=1010;
int T,n,K,vec[o*2][o],sz[o*2],cnt[o*2],p[o*2],id[o][o];char s[o][o];bool del[o*2][o];
inline void slv(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(int i=1;i<2*n;++i) sz[i]=cnt[i]=p[i]=0;
	for(int i=1;i<2*n;++i) for(int j=1;j<=n;++j) del[i][j]=0;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
		id[i][j]=++cnt[i-j+n];
		if(s[i][j]=='1') vec[i-j+n][++sz[i-j+n]]=id[i][j];
	}
	for(int i=1;i<=n-K+1;++i){
		for(++p[n];p[n]<=sz[n]&&(vec[n][p[n]]<=vec[n-1][p[n-1]]||vec[n][p[n]]<=vec[n+1][p[n+1]]);++p[n]);
		if(p[n]>sz[n]){printf("NO\n");return;}
		del[n][vec[n][p[n]]]=1;
		for(int j=n-1;j-K+1>=i;del[j][vec[j][p[j]]]=1,--j){
			for(++p[j];p[j]<=sz[j]&&(vec[j][p[j]]<=vec[j-1][p[j-1]]||vec[j][p[j]]<vec[j+1][p[j+1]]);++p[j]);
			if(p[j]>sz[j]){printf("NO\n");return;}
		}
		for(int j=n+1;n-(j-n)-K+1>=i;del[j][vec[j][p[j]]]=1,++j){
			for(++p[j];p[j]<=sz[j]&&(vec[j][p[j]]<=vec[j+1][p[j+1]]||vec[j][p[j]]<vec[j-1][p[j-1]]);++p[j]);
			if(p[j]>sz[j]){printf("NO\n");return;}
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i,putchar('\n')) for(int j=1;j<=n;++j)
		if(del[i-j+n][id[i][j]]) putchar('0');else putchar('1');
}
int main(){
	for(scanf("%d",&T);T--;slv());
	return 0;
}