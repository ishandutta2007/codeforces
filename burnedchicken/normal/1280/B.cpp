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
	int t,r,c;
	cin >> t;
	bool ok;
	while(t--){
		cin >> r >> c;
		char grid[r][c];
		rep(r) rep1(j,c) cin >> grid[i][j];
		ok=true;
		rep(r) rep1(j,c) if(grid[i][j]=='P') ok=false;
		if(ok){
			cout << "0\n";
			continue;
		}
		ok=true;
		rep(r) if(grid[i][0]=='P') ok=false;
		if(ok){
			cout << "1\n";
			continue;
		}
		ok=true;
		rep(r) if(grid[i][c-1]=='P') ok=false;
		if(ok){
			cout << "1\n";
			continue;
		}
		ok=true;
		rep(c) if(grid[0][i]=='P') ok=false;
		if(ok){
			cout << "1\n";
			continue;
		}
		ok=true;
		rep(c) if(grid[r-1][i]=='P') ok=false;
		if(ok){
			cout << "1\n";
			continue;
		}
		rep(r){
			ok=true;
			rep1(j,c) if(grid[i][j]=='P') ok=false;
			if(ok) break;
		}
		if(ok){
			cout << "2\n";
			continue;
		}
		rep(c){
			ok=true;
			rep1(j,r) if(grid[j][i]=='P') ok=false;
			if(ok) break;
		}
		if(ok){
			cout << "2\n";
			continue;
		}
		if(grid[0][0]=='A'||grid[0][c-1]=='A'||grid[r-1][0]=='A'||grid[r-1][c-1]=='A'){
			cout << "2\n";
			continue;
		}
		ok=false;
		rep(r) if(grid[i][0]=='A'||grid[i][c-1]=='A') ok=true;
		rep(c) if(grid[0][i]=='A'||grid[r-1][i]=='A') ok=true;
		if(ok){
			cout << "3\n";
			continue;
		}
		ok=false;
		rep(r) rep1(j,c) if(grid[i][j]=='A') ok=true;
		if(ok){
			cout << "4\n";
			continue;
		}
		cout << "MORTAL\n";
	}
	return 0;
}