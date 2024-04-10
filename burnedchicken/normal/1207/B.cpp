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
	int n,m;
	cin >> n >> m;
	int a[n][m],b[n][m];
	rep(n) rep1(j,m) cin >> a[i][j];
	rep(n) rep1(j,m) b[i][j]=0;
	vector<pii> ans;
	rep(n-1){
		rep1(j,m-1){
			if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1]){
				b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
				ans.pb(mp(i+1,j+1));
			}
		}
	}
	bool ok=true;
	rep(n) rep1(j,m) if(a[i][j]!=b[i][j]) ok=false;
	if(ok){
		cout << ans.size() << "\n";
		rep(ans.size()) cout << ans[i].first << ' ' << ans[i].second << "\n";
	}
	else cout << "-1\n";
	return 0;
}