/*input
6 4
2 2 2 3 3 3
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , cnt[MAX];
map<int , int> cc;
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) cc[x[i]] ++;
	for(auto to : cc){
		int res = to.B , val = to.A;
		for(int j = val ; j < MAX ; j += val) cnt[j] += res;
	}
	int big = 0;
	RREP(i , m , 1){
		if(cnt[i] >= cnt[big]) big = i;
	}
	if(big == 0){
		cout << "1 0" << endl;
	}
	else {
		cout << big << " " << cnt[big] << endl;
		REP(i , 1 , n + 1) if(big % x[i] == 0) cout << i << " "; cout << endl;
	}
    return 0;
}