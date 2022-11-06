#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
char a[2002][2002];
int tw[4000002];
int main(){
	int T,n,m,i,j,s;
	bool flg=0;
	tw[0]=1;
	for(i=1;i<=4000000;++i)tw[i]=tw[i-1]*2%mod;
	scanf("%d",&T);
	while(T--){
		s=0;flg=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				if(a[i][j]=='#')++s;
				else flg=1;
			}
		}
		if(flg)printf("%d\n",tw[s]);
		else printf("%d\n",(tw[s]+mod-1)%mod);
	}
	return 0;
}