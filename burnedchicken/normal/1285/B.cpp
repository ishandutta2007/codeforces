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
	int t;
	cin >> t;
	loopi(noob,t){
		ll n;
		cin >> n;
		ll a[n];
		loop(n) cin >> a[i];
		ll s[n+1];
		s[0]=0;
		loop(n) s[i+1]=s[i]+a[i];
		bool ok=true;
		loop(n-1){
			if(s[i+1]<=s[0]||s[i+1]>=s[n]) ok=false;
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}