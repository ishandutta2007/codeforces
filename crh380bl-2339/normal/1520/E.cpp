#include<bits/stdc++.h>
using namespace std;
char a[1000002];
int s[1000002];
int main(){
	int T,n,i,j,num;
	long long ans=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,a+1);
		for(i=1;i<=n;++i){
			s[i]=s[i-1]+(a[i]=='*');
		}
		ans=0;
		for(i=1;i<=n;){
			if(a[i]=='*'){
				++i;
				continue;
			}
			num=1;
			for(j=i+1;j<=n&&a[j]!='*';++j)++num;
			ans=ans+1LL*num*min(s[i],s[n]-s[i]);
			i=j;
		}
		printf("%lld\n",ans);
	}
	return 0;
}