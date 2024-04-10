#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m;
int x[MAX][3] , use[MAX];
vector<int> v[MAX];
int cmp1(int a , int b){
	return x[a][1] < x[b][1];
}
int cmp2(int a , int b){
	return x[a][0] < x[b][0];
}
int32_t main(){
	cin >> n >> m;
	REP(i , 0 , n) REP(j , 0 , 3) cin >> x[i][j];
	REP(i , 0 , n) {
		int tmp = x[i][1] - x[i][0] + 1;
		v[tmp].pb(i);
	}
	int ans = 1000000000000000LL;
	REP(i , 0 , n){
		int tmp = x[i][1] - x[i][0] + 1;
		if(use[tmp] || tmp > m) continue;
		if(v[m - tmp].size() == 0) continue;
		use[tmp] = 1;
		sort(ALL(v[tmp]) , cmp1);
		sort(ALL(v[m - tmp]) , cmp2);
		int l = 0 , siz = v[m - tmp].size();
		multiset<int> cc;
		for(auto to : v[m - tmp]) cc.insert(x[to][2]);
		for(auto to : v[tmp]){
			while(l < siz && x[to][1] >= x[ v[m - tmp][l] ][0]){
				cc.erase(cc.find(x[ v[m - tmp][l] ][2]));
				l++;
			}
			if(cc.size()){
				auto tt = cc.begin();
				ans = min(ans , *tt + x[to][2]);	
			}
		}
	}
	if(ans >= 1000000000000000LL) cout << "-1" << endl;
	else cout << ans << endl;
    return 0;
}