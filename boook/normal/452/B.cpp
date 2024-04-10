#include <bits/stdc++.h>
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define PII pair<int , int>
#define mp make_pair
#define pb push_back
#define DBGG(i , j) cout << i << " " << j << endl
#define ALL(i) i.begin() , i.end()
#define A first
#define B second
///--------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f
using namespace std;

int n , m;
vector<PII> sol , ans;
int IN(int a , int b){
	return 0 <= a && a <= n && 0 <= b && b <= m;
}
int DIS(PII a , PII b){
	int x = a.A - b.A;
	int y = a.B - b.B;
	return x * x + y * y;
}
signed main(){
	cin >> n >> m;
	for(auto x : {0 , 1 , n - 1 , n}){
		for(auto y : {0 , 1 , m - 1 , m}){
			if(IN(x , y)) sol.pb(mp(x , y));
		}
	}
	sort(ALL(sol));
	sol.resize(unique(ALL(sol)) - sol.begin());;
	int ansval = 0;
	REP(i , 0 , sol.size()){
		REP(j , 0 , sol.size()){
			if(i == j) continue;
			REP(ii , 0 , sol.size()){
				if(i == ii || j == ii) continue;
				REP(jj , 0 , sol.size()){
					if(i == jj || j == jj || ii == jj) continue;
					int dis = DIS(sol[i] , sol[j]) + DIS(sol[j] , sol[ii]) + DIS(sol[ii] , sol[jj]);
					if(dis > ansval){
						ansval = dis;
						ans.clear();
						ans.pb(sol[i]);
						ans.pb(sol[j]);
						ans.pb(sol[ii]);
						ans.pb(sol[jj]);
					}
				}
			}
		}	
	}
	REP(i , 0 , 4) cout << ans[i].A << " " << ans[i].B << endl;
	return 0;
}