#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const ll mod=1e9+7;

ll Pow(ll a, ll b){
	ll y=1;
	ll z=a;
	while(b>0){
		if(b%2==1){
			y=(y*z);
			b--;
		}
		b=b/2;
		z=(z*z);
	}
	return y;
}

ll dgts(ll n){
	ll n1=n;
	ll x=0;
	while(n1>0){
		n1=n1/3;
		x++;
	}
	return x;
}

vector<ll> f(ll n){
	vector<ll> vec;
	vec.clear();
   	ll x=dgts(n)-1;
	while(x>=0){
		if(n>=2*Pow(3,x)){
			n=n-2*Pow(3,x);
			vec.push_back(2);
		}
		else if(n>=Pow(3,x)){
			n=n-Pow(3,x);
			vec.push_back(1);
		}
		else vec.push_back(0);
		x--;
	}
	return vec;
}

ll g(vector<ll> vec){
	ll x=vec.size();
	ll n=0;
	for(ll i=x-1; i>=0; i--){
		n=n+vec[i]*Pow(3,x-1-i);
	}
	return n;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll q,n,pos1,ans;
	cin >> q;
	loopi(asjkd,q){
		cin >> n;
		vector<ll> vec=f(n);
		pos1=-1;
		ans=-1;
		loop(vec.size()){
			if(vec[i]==0) pos1=i;
			if(vec[i]==2){
				if(pos1==-1){
					ans=Pow(3,vec.size());
				} 
				else{
					vec[pos1]=1;
					loopi(j,vec.size()-pos1-1){
						vec[pos1+1+j]=0;
					}
				}
				break;
			}
		}
		if(ans<0) ans=g(vec);
		cout << ans << endl;
	}
	return 0;
}