#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
char a[N];
ll w[N];
int p,k,x,y;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>p>>k;
		cin>>(a+1);
		cin>>x>>y;
		ll ans=1e18;
		for(i=0;i<=n;i++) w[i]=0;
		for(i=n-p;i>=0;i--){
			if(i+k+p>n) w[i]=(a[i+p]=='0')*x;
			else w[i]=w[i+k]+(a[i+p]=='0')*x;
			ans=min(ans,i*y+w[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}