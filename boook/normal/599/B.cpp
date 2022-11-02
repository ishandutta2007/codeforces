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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m;
int f[MAX] , b[MAX];
vector<int> v , ans;
int32_t main(){
	int ok = 1;

	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> f[i] , v.pb(f[i]);
	REP(i , 1 , m + 1) cin >> b[i];

	map<int , vector<int>> cc;
	REP(i , 1 , n + 1) cc[f[i]].pb(i);
	REP(i , 1 , m + 1){
		if(cc.find(b[i]) == cc.end()) {
			ok = -2; break;
		}
		else if(cc[b[i]].size() != 1) ok = -1;
		else ans.pb(cc[b[i]][0]);
	}

	if(ok == -2) cout << "Impossible" << endl;
	else if(ok == -1) cout << "Ambiguity" << endl;
	else {
		cout << "Possible" << endl;
		for(auto to : ans) cout << to << " "; cout << endl;
	}
    return 0;
}