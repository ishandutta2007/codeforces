#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
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
 
const ll Mod=1000000007,Mod2=998244353;
int t,n,a[300005];
string str,ans;
bool ok;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		rep(n) cin >> a[i];
		ok=true;
		rep(n) if(a[i]<min(i,n-1-i)) ok=false;
		if(!(n&1)) if(a[n/2-1]==n/2-1&&a[n/2]==n/2-1) ok=false;
		cout << (ok?"Yes\n":"No\n");
	}
	return 0;
}