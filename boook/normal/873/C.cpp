/*input
3 2 1
1 0
0 1
0 0
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000
#define INF 0x3f3f3f3f

int n , m , k , sum = 0 , chg = 0;
void solve(vector<int> v){
	while(v.size() < n + k + 10) v.pb(0);
	REP(i , 1 , v.size()) v[i] += v[i - 1];
	int big = 0 , cnt = 0;
	REP(i , 1 , n + 1){
		if(v[i + k - 1] - v[i - 1] == cnt) big = min(big , v[i - 1]);
		if(v[i + k - 1] - v[i - 1] >  cnt){
			cnt = v[i + k - 1] - v[i - 1];
			big = v[i - 1];
		}
	}
	sum += cnt , chg += big;
}
vector<int> v[MAX];
int32_t main(){
	IOS , cin >> n >> m >> k;
	REP(i , 1 , m + 1) v[i].pb(0);
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1){
			int val; cin >> val;
			v[j].pb(val);
		}
	}
	REP(i , 1 , m + 1) solve(v[i]);
	cout << sum << " " << chg << endl;
    return 0;
}