#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const ll mod=1e9+7;

ll F(ll x){
	ll a,b,c;
	if(x<=1) return 1;
	a=b=1;
	loop(x-1){
		c=(a+b)%mod;
		a=b;
		b=c;
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	string s;
	cin >> s;
	ll ans,k,l,m;
	ans=1;
	k=l=0;
	loop(s.size()){
		if(s[i]=='m'||s[i]=='w'){
			cout << 0 << endl;
			return 0;
		}
		if(k>0){
			if(s[i]!='n'){
				ans=(ans*F(k))%mod;
				k=0;
			}
			if(k>0&&i==s.size()-1){
				if(s[i]=='n') k++;
				ans=(ans*F(k))%mod;
				k=0;
			}
		}
		if(l>0){
			if(s[i]!='u'){
				ans=(ans*F(l))%mod;
				l=0;
			}
			if(l>0&&i==s.size()-1){
				if(s[i]=='u') l++;
				ans=(ans*F(l))%mod;
				l=0;
			}
		}
		if(s[i]=='n') k++;
		else if(s[i]=='u') l++;
	}
	cout << ans << endl;
	return 0;
}