#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=b; i<(int(a)); i++)
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,ans=0,x=0,y=0,z=0;
	cin >> n;
	ll a[n];
	rep(n) cin >> a[i];
	rep(n){
		if(a[i]>0){
			x++;
			ans+=a[i]-1;
		}
		else if(a[i]==0){
			y++;
			ans++;
		}
		else{
			z++;
			ans+=-a[i]-1;
		}
	}
	if(y) cout << ans << "\n";
	else if(z%2==0) cout << ans << "\n";
	else cout << ans+2 << "\n";
	return 0;
}