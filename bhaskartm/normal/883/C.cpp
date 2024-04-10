#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll ceil(ll b1,ll b2){
	if(b1%b2){
		return b1/b2+1;
	}
	return b1/b2;
}
ll min(ll a,ll b){
	if(b<a){
		return b; 
	}
	return a;
}
ll inf=1e18;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll f,T,t0,a1,t1,p1,a2,t2,p2;
	cin>>f>>T>>t0>>a1>>t1>>p1>>a2>>t2>>p2;
	ll b0=f*t0-T;
	if(b0<=0){
		cout<<0<<endl;
		return 0;
	}
	if(t0<=t1 && t0<=t2){
		cout<<-1<<endl;
		return 0;
	}
	if(t0<=t1 || t0<=t2){
		if(t0<=t1){
			swap(t1,t2);
			swap(p1,p2);
			swap(a1,a2);
		}
		ll c1=ceil(b0,t0-t1);
		if(c1>f){
			cout<<-1<<endl;
		}else{
			cout<<p1*ceil(c1,a1)<<endl;
		}
		return 0;
	}
	ll b1=t0-t1;
	ll b2=t0-t2;
	ll ans=inf;
	for(ll c1=0;c1<=f;c1++){
		if(b1*c1+b2*(f-c1)<b0){
			continue;
		}
		ll s=0;
		ll e=f-c1;
		while(s<e){
			ll mid=(s+e)/2;
			if(b1*c1+b2*mid>=b0){
				e=mid;
			}else{
				s=mid+1;
			}
		}
		ans=min(ans,p1*ceil(c1,a1)+p2*ceil(s,a2));
	}
	if(ans==inf){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
}