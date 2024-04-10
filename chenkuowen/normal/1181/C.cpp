#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e3;
char s[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
struct Key{ int t,cnt,mi; };
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(s[i][j]==s[i][j-1])
				a[i][j]=a[i][j-1]+1;
			else a[i][j]=1;
		}
	long long ans=0;
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			int t=i;
			for(;s[i][j]==s[t][j];++i); --i;
//			printf("|%d %d|",t,i);
			int cnt=i-t+1,mi=1e9;
			for(int k=t;k<=i;++k) mi=min(a[k][j],mi);
			for(int k=t-1;k>=t-cnt;--k)
				if(k<1||s[k][j]!=s[t-1][j]){
					mi=0; break;
				}else mi=min(mi,a[k][j]);
			for(int k=i+1;k<=i+cnt;++k)
				if(k>n||s[k][j]!=s[i+1][j]){
					mi=0; break;
				}else mi=min(mi,a[k][j]);
			ans+=mi; 
//			printf("<%d %lld>",mi,ans);
		}		
	}
	printf("%lld\n",ans);
	return 0;
}