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
	int n;
	cin >> n;
	char c[n][5];
	rep(n) rep1(j,5) cin >> c[i][j];
	bool ok=false;
	rep(n){
		if(c[i][0]=='O'&&c[i][1]=='O'){
			c[i][0]=c[i][1]='+';
			ok=true;
			break;
		}
		if(c[i][3]=='O'&&c[i][4]=='O'){
			c[i][3]=c[i][4]='+';
			ok=true;
			break;
		}
	}
	if(ok){
		cout << "YES\n";
		rep(n){
			rep1(j,5) cout << c[i][j];
			cout << "\n";
		}
	}
	else cout << "NO\n";
	return 0;
}