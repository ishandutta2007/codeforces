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
	ll n;
	cin >> n;
	ll a[n];
	loop(n) cin >> a[i];
	ll b,w;
	b=w=0;
	loop(n){
		if(i%2==0){
			b+=(a[i]+1)/2;
			w+=a[i]/2;
		}
		else{
			b+=a[i]/2;
			w+=(a[i]+1)/2;
		}
	}
	cout << min(b,w) << "\n";
	return 0;
}