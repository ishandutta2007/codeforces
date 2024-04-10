#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,a[1000010],last[200010],dp[200010],ans;
int main(){
	T=read();
	while(T--){
		n=read();ans=1e9;
		for(i=1;i<=n;i++)last[i]=0;
		for(i=1;i<=n;i++){
			a[i]=read();
			dp[i]=dp[last[a[i]]]+(last[a[i]]!=i-1);
			last[a[i]]=i;
//			cout<<dp[i]<<endl;
		}
		for(i=1;i<=n;i++)
			if(last[a[i]]==i)ans=min(ans,dp[i]+(i!=n));
		cout<<ans<<endl;
	}
	return 0;
}