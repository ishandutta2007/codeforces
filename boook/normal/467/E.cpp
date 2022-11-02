/*input
10
35 1 2 1 2 35 100 200 100 200
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 500900
#define INF 0x3f3f3f3f

int n , x[MAX];
vector<int> ans , sol;
cc_hash_table<int , int> tag , sum;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int now = 1;
	while(now <= n){
		if(tag[x[now]]){
			ans.pb(tag[x[now]]) , ans.pb(x[now]);
			ans.pb(tag[x[now]]) , ans.pb(x[now]);
			tag.clear() , sum.clear();
			now ++;
		}
		else {
			while(sol.size() && sum[x[now]] && (sum[x[now]] > 1 || sol.back() != x[now])){
				tag[sol.back()] = x[now];
				sum[sol.back()] --;
				sol.pop_back();
			}
			sol.pb(x[now]);
			sum[x[now]] ++;
			now ++;
		}
	}
	cout << ans.size() << endl;
	for(auto to : ans) cout << to << " ";
	cout << endl;
    return 0;
}