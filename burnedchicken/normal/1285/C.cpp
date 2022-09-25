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
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll x,ans,k;
	cin >> x;
	ll y=sqrt(x)+1;
	loop(y){
		k=i;
		if(k==0) continue;
		if(x%k==0) if(__gcd(k,x/k)==1) ans=k;
	}
	cout << ans << ' ' << x/ans << "\n";
	return 0;
}