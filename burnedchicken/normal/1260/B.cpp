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
		if((x+y)%3!=0){
			cout << "NO\n";
			continue;
		}
		if(x*y==0){
			if(x!=0) cout << "NO\n";
			else if(y!=0) cout << "NO\n";
			else cout << "YES\n";
			continue;
		}
		if((max(x,y)-1)/min(x,y)>1){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}