#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
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
	int t,n,d;
	cin >> t;
	bool ok;
	while(t--){
		cin >> n >> d;
		ok=false;
		rep(100000){
			if(i==n) break;
			if(i+ceil(d/(i+1.0))<=n){
				cout << "YES\n";
				ok=true;
				break;
			}
		}
		if(!ok) cout << "NO\n";
	}
	return 0;
}