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
	int n,m,ans=0;
	cin >> n >> m;
	int l[n],r[n];
	rep(n) cin >> l[i] >> r[i];
	bool covered[m+1];
	rep(m+1) covered[i]=false;
	covered[0]=true;
	rep(n) rep2(j,l[i],r[i]+1) covered[j]=true;
	rep(m+1) if(!covered[i]) ans++;
	cout << ans << "\n";
	rep(m+1) if(!covered[i]) cout << i << ' ';
	cout << "\n";
	return 0;
}