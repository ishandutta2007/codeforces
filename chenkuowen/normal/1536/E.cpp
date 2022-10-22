#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
char s[2005];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n,m,cnt=0; scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%s",s+1);
			for(int j=1;j<=m;++j)
				cnt+=int(s[j]=='#');
		}
		int ans=fpow(2,cnt);
		if(cnt==n*m) ans=(ans+MOD-1)%MOD;
		printf("%d\n",ans);
	}
	return 0;
}