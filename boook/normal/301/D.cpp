/*input
10 9
1 2 3 4 5 6 7 8 9 10
1 10
2 9
3 8
4 7
5 6
2 2
9 10
5 10
4 10
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
#define int long long
#define MAX 200090
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
	for(int i = from ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int n , m , x[MAX] , y[MAX];
int ql[MAX] , qr[MAX] , sol[MAX] , ans[MAX];
vector<int> v[MAX];
int cmp(int a , int b){ return qr[a] < qr[b]; }
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) y[x[i]] = i;
	REP(i , 1 , m + 1) cin >> ql[i] >> qr[i];
	REP(i , 1 , m + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + m , cmp);

	REP(i , 1 , n + 1){
		for(int j = i + i ; j <= n ; j += i){
			int ii = y[i] , jj = y[j];
			v[max(ii , jj)].pb(min(ii , jj));
		}
	}

	int po = 1;
	REP(i , 1 , n + 1){
		for(auto to : v[i]){
			update(1 , 1);
			update(to + 1 , -1);
		}
		while(po <= m && qr[sol[po]] <= i){
			int id = sol[po];
			ans[id] = query(ql[id]) + qr[id] - ql[id] + 1;
			po ++;
		}
	}

	REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}