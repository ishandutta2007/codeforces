#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
char s[N];
int ED[N];
int lst;
int main(){
	int T,i,j,n;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		//for(i=1;i<=n+2;++i)ED[i]=0;
		for(i=j=1;i<=n;++i){
			if(s[i]=='?')continue;
			if(j<i)j=i;
			if(s[j]=='?'){
				ED[i]=j;
				continue;
			}
			lst=s[j]-'0';
			while(((lst+'0')!=s[j+1])&&j<n){
				lst^=1;
				++j;
			}
			ED[i]=j;
		}
		i=n;
		while(s[i]=='?'&&i>=1){
			ED[i]=n;
			--i;
		}
		for(;i>=1;--i)if(s[i]=='?')ED[i]=ED[i+1];
		long long ans=0;
		for(i=1;i<=n;++i){
			ans=ans+(ll)(ED[i]-i+1LL);
		}
		printf("%lld\n",ans);
	}
	return 0;
}