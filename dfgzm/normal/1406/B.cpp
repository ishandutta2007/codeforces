#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		ll ans=-1e18;
		ans=max(ans,1ll*a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]);
		ans=max(ans,1ll*a[n]*a[n-1]*a[n-2]*a[1]*a[2]);
		ans=max(ans,1ll*a[n]*a[3]*a[4]*a[1]*a[2]);cout<<ans<<endl;
	}
}