#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;
 
const int Mod=1e9+7;

ll dgts(ll n){
	ll n1=n;
	ll x=0;
	while(n1>0){
		n1=n1/2;
		x++;
	}
	return x;
}

ll cnt(ll n,ll m){
	if(m>n||m<=0) return 0;
	ll ans,x;
	if(m%2==1){
		x=dgts(n)-dgts(m);
		ans=pow2(x)-1;
		if((m+1<<x)<=n) ans+=pow2(x);
		else if((m<<x)<=n) ans+=n-(m<<x)+1;
	}
	else{
		x=dgts(n)-dgts(m)+1;
		ans=pow2(x)-2;
		if((m+2<<x-1)<=n) ans+=pow2(x);
		else if((m<<x-1)<=n) ans+=n-(m<<x-1)+1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,k,x;
	cin >> n >> k;
	ll ans1,ans2;
	ans1=ans2=-1;
	loop(dgts(n)){
		x=n>>i;
		if(x%2==1){
			if(cnt(n,x)>=k){
				ans1=x;
				break;
			}
			if(dgts(x-2)==dgts(x)&&cnt(n,x-2)>=k){
				ans1=x-2;
				break;
			}
		}
		else{
			if(dgts(x-1)==dgts(x)&&cnt(n,x-1)>=k){
				ans1=x-1;
				break;
			}
			if(dgts(x-3)==dgts(x)&&cnt(n,x-3)>=k){
				ans1=x-3;
				break;
			}
		}
	}
	loop(dgts(n)){
		x=n>>i;
		if(x%2==0){
			if(cnt(n,x)>=k){
				ans2=x;
				break;
			}
			if(dgts(x-2)==dgts(x)&&cnt(n,x-2)>=k){
				ans2=x-2;
				break;
			}
		}
		else{
			if(dgts(x-1)==dgts(x)&&cnt(n,x-1)>=k){
				ans2=x-1;
				break;
			}
			if(dgts(x-3)==dgts(x)&&cnt(n,x-3)>=k){
				ans2=x-3;
				break;
			}
		}
	}
	cout << max(ans1,ans2) << "\n";
	return 0;
}