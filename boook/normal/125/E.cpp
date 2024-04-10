/*input
10 30 4
3 5 7
8 5 1
3 6 5
6 8 10
5 6 4
7 10 7
4 3 4
6 7 7
3 1 4
7 1 4
9 8 5
2 7 5
9 10 1
8 4 2
10 8 5
8 1 6
3 2 4
4 1 5
7 3 2
1 2 1
10 5 1
10 2 7
7 5 1
4 5 9
10 6 10
5 9 7
10 3 7
2 4 10
1 9 5
10 1 2
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
#define MAX 100006
#define INF 0x3f3f3f3f

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(now); }
} ds;
int n , m , k;
int e[MAX][3] , sol[MAX] , one[MAX] , use[MAX];
int val , gap = -112345;


int cmp(int a , int b){
	return mp(e[a][2] - one[a] * gap , one[a]) < mp(e[b][2] - one[b] * gap , one[b]);
}
int judge(int need){
	sort(sol + 1 , sol + 1 + m , cmp);
	REP(i , 1 , m + 1) use[i] = 0;
	ds.init() , val = 0;
	int cnt = 0 , times = 0;
	REP(idx , 1 , m + 1){
		int i = sol[idx] , a = e[i][0] , b = e[i][1] , v = e[i][2];
		if(ds[a] != ds[b] && (need == 0 || cnt - one[i] <= k)){
			ds.Union(a , b);
			val += v;
			times ++;
			use[i] = 1;
			cnt -= one[i];

		}
	}
	if(times != n - 1) return -1;
	return cnt;
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , m + 1) cin >> e[i][0] >> e[i][1] >> e[i][2];
	REP(i , 1 , m + 1) if(e[i][0] == 1 || e[i][1] == 1) one[i] = -1;
	REP(i , 1 , m + 1) sol[i] = i;
	// REP(i , 1 , m + 1) cout << one[i] << " " ; cout << endl;
	int base = -112345;
	RREP(i , 20 , 0){
		gap = base + (1 << i);
		int res = judge(0);
		if(res >= k) base = gap;
	}
	gap = base;
	if(judge(1) == -1) cout << -1 << endl;
	else {
		cout << n - 1 << endl;
		REP(i , 1 , m + 1) if(use[i] == 1) cout << i << " " ; cout << endl;
	}
    return 0;
}