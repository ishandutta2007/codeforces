#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll c,d,x;
ll ans=0;
int pri[20000004];
ll pw[64];
ll sol(ll gcd,ll lcm){
	if(lcm%gcd)return 0;
	return pw[pri[lcm/gcd]];
}
ll solve(ll a){
	if((d*a+x)%c)return 0;
	return sol(a,(d*a+x)/c);
}
int main(){
	for(int i=2;i<=2e7;i++)if(!pri[i])
		for(int j=i;j<=2e7;j+=i)pri[j]++;
	pw[0]=1;for(int i=1;i<60;i++)pw[i]=pw[i-1]*2;
	cin>>T;
	while(T--){
		cin>>c>>d>>x;ans=0;
		for(int i=1;i*i<=x;i++)if(x%i==0){
			ans+=solve(i);
			if(i!=x/i)ans+=solve(x/i);
		}
		cout<<ans<<endl;
	}
}