/*input
3
1 2
1 2
1 2
2
1 2 1
1 2 2
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , x[MAX][3] , sol[MAX];
int cmp(int a , int b){
	if(x[a][0] != x[b][0])
		return x[a][0] < x[b][0];
	if(x[a][0] != x[b][0])
		return x[a][1] > x[b][1];
	return a > b;
}
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	cin >> m;
	REP(i , n + 1 , n + m + 1) cin >> x[i][0] >> x[i][1] >> x[i][2];

	REP(i , 1 , n + m + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + n + m , cmp);

	set<PII> cc;
	REP(tt , 1 , n + m + 1){
		int i = sol[tt];
		if(i > n) cc.insert(mp(x[i][1] , i));
		else {
			auto tmp = cc.lower_bound(mp(x[i][1] , -1));
			if(tmp == cc.end()) return cout << "NO" << endl , 0;
			x[i][2] = tmp->B;
			x[tmp->B][2] --;
			if(x[tmp->B][2] == 0) cc.erase(tmp);
		}
	}
	cout << "YES" << endl;
	REP(i , 1 , n + 1) cout << x[i][2] - n << " "; cout << endl;
    return 0;
}