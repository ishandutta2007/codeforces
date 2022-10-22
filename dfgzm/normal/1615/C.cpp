#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=500005,mod=1000000007;
int T,n,ans,cnts,cntt;
string s,t;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cin>>s>>t,cnts=cntt=0;
		for(int i=0;i<n;i++)
			cnts+=s[i]=='1',cntt+=t[i]=='1';
		ans=n+1;
		if(cntt==cnts){
			int cnt=0;
			for(int i=0;i<n;i++)
				cnt+=s[i]=='1'&&t[i]=='1';
			ans=min(ans,(cnts-cnt)*2);
		}
		if(cntt==1+(n-cnts)){
			int cnt=0;
			for(int i=0;i<n;i++)
				cnt+=(s[i]=='1'&&t[i]=='1')+(s[i]=='0'&&t[i]=='0');
			ans=min(ans,cnt);
		}
		printf("%d\n",ans==n+1? -1:ans);
	}
	return 0;
}