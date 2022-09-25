#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	loopi(noob,n){
		ll x,y;
		cin >> x >> y;
		ll ans=0;
		while(x>0){
			ans+=(y/x)*(y/x);
			y-=y/x;
			x--;
		}
		cout << ans << "\n";
	}
	return 0;
}