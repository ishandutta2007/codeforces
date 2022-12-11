#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;

int main(){
	ll n;
	ll k = 0;
	cin>>n;
	Vll arr(n);
	for(int i = 0;i < n;++i) {
		cin>>arr[i];
		k += arr[i];
	}
	if(n < 3 || k%3 != 0) cout<<0<<endl;
	else{
		ll t = 0,ct = 0,p = 0;
		for(int i = 0;i < n-1;++i){
			p += arr[i];
			if(p == (2*k)/3) t += ct;
			if(p == k/3) ++ct;
		}
		cout<<t<<endl;
	}

}