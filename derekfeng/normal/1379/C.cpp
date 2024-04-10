#include <bits/stdc++.h>
using namespace std;
int T,n,m;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
pii pos[100004];
int num[100004];
ll d[100004];
int main(){
	cin>>T;
	while(T--){
		ll ans=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++)cin>>pos[i].fi>>pos[i].se,num[i]=-pos[i].fi;
		sort(num+1,num+1+m);
		for(int i=1;i<=m;i++)d[i]=d[i-1]-num[i];
		for(int i=1;i<=m;i++){
			int x=-pos[i].se;
			int nn=n;
			int p=upper_bound(num+1,num+1+m,x)-num-1;
			ll ret=d[p];
			if(p>=n)ret=d[n];
			else{
				nn-=p;
				if(pos[i].fi<pos[i].se)nn--,ret+=pos[i].fi;
				ret+=1ll*nn*pos[i].se;
			}
			ans=max(ans,ret);
//			cout<<pos[i].se<<" "<<p<<" "<<ret<<"\n";
		}
		cout<<ans<<"\n";
	}
}