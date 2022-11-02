/*input
8 6
5 6
5 7
5 8
6 2
2 1
7 3
1 3
1 4
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
#define MAX 300900
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int query(int l , int r){
	return query(r) - query(l - 1);
}
int n , m , x[MAX][2] , cnt[MAX];
long long ans = 0;
vector<int> v[MAX];

void DEL(PII val){ update(val.A , -1); }
void ADD(PII val){ update(val.A , 1); }
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) REP(j , 0 , 2) cin >> x[i][j];
	REP(i , 1 , n + 1) REP(j , 0 , 2) v[x[i][j]].pb(i);
	REP(i , 1 , n + 1) REP(j , 0 , 2) cnt[x[i][j]] ++;
	REP(i , 1 , n + 1) ADD(mp(cnt[i] , i));
	// put(root) , cout << endl << "------------" << endl; 
	REP(ii , 1 , n + 1){
		for(auto to : v[ii]){
			DEL(mp(cnt[x[to][0]] , x[to][0])) , cnt[x[to][0]] --;
			DEL(mp(cnt[x[to][1]] , x[to][1])) , cnt[x[to][1]] --;
			ADD(mp(cnt[x[to][0]] , x[to][0]));
			ADD(mp(cnt[x[to][1]] , x[to][1]));
		}
		if(m <= v[ii].size()) ans += n - 1;
		else ans += query(m - (int)v[ii].size() , n);

	// put(root) , cout << ans << endl << "------------" << endl; 
		for(auto to : v[ii]){
			DEL(mp(cnt[x[to][0]] , x[to][0])) , cnt[x[to][0]] ++;
			DEL(mp(cnt[x[to][1]] , x[to][1])) , cnt[x[to][1]] ++;
			ADD(mp(cnt[x[to][0]] , x[to][0]));
			ADD(mp(cnt[x[to][1]] , x[to][1]));
		}
	}
	cout << ans / 2 << endl;
    return 0;
}