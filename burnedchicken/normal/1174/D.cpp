#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;

ll v2(ll n){
	ll x=0;
	while(n%2==0){
		x++;
		n=n/2;
	}
	return x;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,x;
	cin >> n >> x;
	if(x>=pow2(n)){
		cout << pow2(n)-1 << "\n";
		loop(pow2(n)-1) cout << pow2(v2(i+1)) << ' ';
		cout << "\n";
	}
	else{
		cout << pow2(n-1)-1 << "\n";
		loop(pow2(n-1)-1){
			if(v2(i+1)>=v2(x)) cout << pow2(v2(i+1)+1) << ' ';
			else cout << pow2(v2(i+1)) << ' ';
		}
		cout << "\n";
	}
	return 0;
}