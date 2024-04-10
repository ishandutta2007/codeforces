#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll t[N];
int main(){
	ll n,m,a,d;
	cin>>n>>m>>a>>d;
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	ll ans=0;
	ll last=0;
	ll d1=(1+d/a);
	for(int i=0;i<m;i++){
		if(last>=t[i]){
			continue;
		}
		ll a_id=(last/a)+1;
		if(a_id>n || a_id*a>t[i]){
			ans+=1;
			last=t[i]+d;
			continue;
		}
		ll x=(t[i]-a_id*a)/(d1*a);
		ll new_id=a_id+x*d1;
		if(new_id>n){
			ans+=((n-a_id)/d1+1);
			ans+=1;
			last=t[i]+d;
			continue;
		}
		ans+=(x+1);
		if(a*new_id+d>=t[i]){
			last=a*new_id+d;
		}else{
			ans+=1;
			last=t[i]+d;
		}
	}
	ll a_id=(last/a)+1;
	if(a_id<=n){
		ans+=((n-a_id)/d1+1);
	}
	cout<<ans<<endl;
}