/*input
4
0 0
2 0
0 2
2 2
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
#define int long long
#define MAX 100900
#define INF 10000000000000000LL

int n;
PII x[MAX] , fr[MAX] , ba[MAX];
int judge(int len){
	int rpo = 1;
	REP(i , 1 , n + 1){
		while(rpo + 1 <= n && x[rpo + 1].A - x[i].A <= len) rpo ++;
		int sml = min(fr[i - 1].A , ba[rpo + 1].A);
		int big = max(fr[i - 1].B , ba[rpo + 1].B);
		if(big - sml <= len) return 1;
	}
	return 0;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
	REP(i , 1 , n + 1) x[i] = mp(x[i].A - x[i].B , x[i].A + x[i].B);
	sort(x + 1 , x + 1 + n);

	fr[0] = mp(INF , -INF);
	REP(i , 1 , n + 1){
		fr[i].A = min(fr[i - 1].A , x[i].B);
		fr[i].B = max(fr[i - 1].B , x[i].B);
	}
	ba[n + 1] = mp(INF , -INF);
	RREP(i , n , 1){
		ba[i].A = min(ba[i + 1].A , x[i].B);
		ba[i].B = max(ba[i + 1].B , x[i].B);
	}
	int ans = -1;
	RREP(i , 45 , 0){
		int to = ans + (1LL << i);
		if(judge(to) == 0) ans = to;
	} ans ++;
	if(ans % 2 == 0) cout << ans / 2 << endl;
	if(ans % 2 == 1) cout << ans / 2 << ".5" << endl;
    return 0;
}