#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<ll, ll> P;

#define X first
#define Y second

int main(){
	ll a,b,n;
	P res = P(1e9,1e9);
	cin>>n>>a>>b;
	n *= 6;
	ll a1 = max(a,b);
	ll b1 = min(a,b);
	if(a*b >= n) cout<<a*b<<endl<<a<<" "<<b<<endl;
	else{
		for(ll i = b1;i <= sqrt(n)+1;++i){
			if(ll((n+i-1)/i) < a1) break;
			if(n%i == 0){
				if(a1 == a){
					res.X = n/i;
					res.Y = i;
				}
				else {
					res.X = i;
					res.Y = n/i;
				}
				break; 
			}
			if(res.X*res.Y > i*ll((n+i-1)/i)) {
				if(a1 == a){
					res.X = (n+i-1)/i;
					res.Y = i;
				}
				else {
					res.X = i;
					res.Y = (n+i-1)/i;
				}
			}
		}
		cout<<res.X*res.Y<<endl<<res.X<<" "<<res.Y<<endl;
	}
}