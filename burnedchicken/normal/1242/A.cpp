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
ll n,m,y;
vector<ll> vec;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	if(n==1){
		cout << "1\n";
		return 0;
	}
	y=sqrt(n)+2;
	y=min(y,n+1);
	m=n;
	rep2(i,2,y){
		while(m%i==0){
			if(vec.empty()) vec.pb(i);
			else if(i!=vec.back()) vec.pb(i);
			m/=i;
		}
		if(m==1) break;
	}
	if(m>1) vec.pb(m);
	if(vec.size()>=2) cout << "1\n";
	else cout << vec[0] << '\n';
	return 0;
}