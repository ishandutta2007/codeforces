/*input
5
2 3 5 7 11
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
#define MAX 300090
#define INF 0x3f3f3f3f

int n , sp[MAX][20] , one[MAX] , l[MAX] , r[MAX];
int query(int ql , int qr){
	int tmp = one[qr - ql + 1];
	return __gcd(sp[ql][tmp] , sp[qr - (1 << tmp) + 1][tmp]);
}
int32_t main(){
	IOS , cin >> n;

	REP(i , 2 , n + 1) one[i] = one[i >> 1] + 1;
	REP(i , 1 , n + 1) cin >> sp[i][0];
	REP(j , 1 , 20) REP(i , 1 , n + 1){
		int to = i + (1 << (j - 1));
		if(to > n) break;
		sp[i][j] = __gcd(sp[i][j - 1] , sp[to][j - 1]);
	}
	REP(i , 1 , n + 1){
		int now , to;
		now = i;
		RREP(j , 19 , 0){
			to = now + (1 << j);
			if(to <= n && query(now , to) % sp[i][0] == 0) now = to; 
		}
		r[i] = now;

		now = i;
		RREP(j , 19 , 0){
			to = now - (1 << j);
			if(to >= 1 && query(to , now) % sp[i][0] == 0) now = to;
		}
		l[i] = now;
	}

	int big = 0;
	REP(i , 1 , n + 1) big = max(big , r[i] - l[i]);
	vector<int> ans;
	REP(i , 1 , n + 1){
		if(r[i] - l[i] == big) ans.pb(l[i]);
	}
	sort(ALL(ans)) , ans.resize(unique(ALL(ans)) - ans.begin());
	cout << ans.size() << " " << big << endl;
	for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}