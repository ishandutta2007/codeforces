#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,p,k,i,t;
string st;
int ans,f[100005],x,y;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>p>>k>>st;st=" "+st;
		cin>>x>>y;ans=0x7fffffff;
		for(i=n;i>=1;i--){
			f[i]=(st[i]=='0')*x;
			if(i+k<=n)f[i]+=f[i+k];
			if(i>=p) ans=min(ans,f[i]+max(0,i-p)*y);
		}
		cout<<ans<<endl;
	}
	return 0;
}