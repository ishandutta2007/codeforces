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
int n,a[1000005];
ll pre[1000005]={0},ans=1e18,x,y;
vector<ll> vec;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i];
	rep(n) pre[i+1]=pre[i]+a[i];
	if(pre[n]==1){
		cout << "-1\n";
		return 0;
	}
	y=sqrt(pre[n])+2;
	y=min(y,pre[n]+1);
	x=pre[n];
	rep2(i,2,y){
		if(!(x%i)){
			vec.pb(i);
			x/=i;
		}
		while(!(x%i)){
			x/=i;
		}
		if(x==1) break;
	}
	if(x>1) vec.pb(x);
	rep(vec.size()){
		x=0;
		rep1(j,n-1){
			x=x+min(pre[j+1]%vec[i],vec[i]-pre[j+1]%vec[i]);
		}
		ans=min(ans,x);
	}
	cout << ans << '\n';
	return 0;
}