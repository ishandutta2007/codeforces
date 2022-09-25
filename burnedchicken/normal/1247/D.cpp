#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;
 
ll Pow(ll a, ll b){
	ll y=1;
	ll z=a;
	while(b>0){
		if(b%2==1){
			y=(y*z);
			if(y>1e5) return 1e5+5;
			b--;
		}
		b=b/2;
		z=(z*z);
	}
	return y;
}
 
ll ptr(ll x1,ll x2){
	ll y=1;
	ll z=0;
	bool prime=true;
	for(int i=2; i<=sqrt(x1); i++){
		z=0;
		while(x1%i==0){
			prime=false;
			x1=x1/i;
			z++;
		}
		if(z>0) y=y*Pow(i,x2-z);
		if(y>1e5) return 1e5+5;
	}
	if(x1>1) y=y*Pow(x1,x2-1);
	if(y>1e5) return 1e5+5;
	return y;
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,k,cnt,x,ans;
	cin >> n >> k;
	ll a[n];
	ll maxn=1e5+5;
	ll b[maxn];
	loop(n) cin >> a[i];
	if(k>32){
		x=0;
		loop(n) if(a[i]==1) x++;
		cout << x*(x-1)/2 << endl;
		return 0;
	}
	loop(maxn) b[i]=0;
	loop(n){
		x=a[i];
		cnt=0;
		for(int j=2; j<=sqrt(x); j++){
			cnt=0;
			while(x%j==0){
				x=x/j;
				cnt++;
				if(cnt==k){
					a[i]=a[i]/pow(j,k);
					cnt=0;
				}
			}
		}
		b[a[i]]++;
	}
	ans=0;
	loop(maxn){
		if(b[i]==0) continue;
		if(ptr(i,k)>=1e5) continue;
		if(i==ptr(i,k)) ans=ans+b[i]*(b[i]-1);
		else ans=ans+b[i]*b[ptr(i,k)];
	}
	ans=ans/2;
	cout << ans << endl;
	return 0;
}