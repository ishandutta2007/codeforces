#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;
 
const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	ll a,b,x,ans;
	loopi(noob,t){
		cin >> a >> b;
		x=abs(a-b);
		ans=ceil((sqrt(8*x+1)-1)/2);
		loop(4) if((ans*(ans+1)/2-x)%2!=0) ans++;
		cout << ans << "\n";
	}
	return 0;
}