#include<bits/stdc++.h>
using namespace std;
int t,n,q;
char s[200];
bool has[200][2];
bool sah[200][2];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		memset(has,0,sizeof has);
		memset(sah,0,sizeof sah);
		for(int i=1;i<=n;i++)
			has[i][0]=has[i-1][0],
			has[i][1]=has[i-1][1],
			has[i][s[i]-'0']=1;
		for(int i=n;i>=1;i--)
			sah[i][0]=sah[i+1][0],
			sah[i][1]=sah[i+1][1],
			sah[i][s[i]-'0']=1;
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			puts((has[l-1][s[l]-'0']||sah[r+1][s[r]-'0'])?"YES":"NO");
		}
	}
	return 0;
}