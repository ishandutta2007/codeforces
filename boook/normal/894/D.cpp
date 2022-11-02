/*input
6 4
2
1
1
3
2
2 4
1 3
3 2
1 7
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)


int n , m;
int lv[MAX] , rv[MAX];
vector<int> v[MAX * 4] , sum[MAX * 4];
void DFS(int now){
	if(now > n) return ;
	v[now].pb(0);
	DFS(ls) , DFS(rs);
	int apo = 0 , bpo = 0;
	while(apo < v[ls].size() || bpo < v[rs].size()){
		if(apo == v[ls].size()) v[now].pb(v[rs][bpo ++] + rv[now]);
		else if(bpo == v[rs].size()) v[now].pb(v[ls][apo ++] + lv[now]);
		else if(v[ls][apo] + lv[now] <= v[rs][bpo] + rv[now]){
			v[now].pb(v[ls][apo ++] + lv[now]);
		}
		else if(v[ls][apo] + lv[now] >= v[rs][bpo] + rv[now]){
			v[now].pb(v[rs][bpo ++] + rv[now]);
		}
	}
	sum[now].pb(0);
	REP(i , 1 , v[now].size()){
		sum[now].pb(sum[now][i - 1] + v[now][i]);
	}
}
int query(int dot , int vv){
	// DB4("dot = " , dot , "vv = " , vv);
	if(v[dot].size() == 0 || vv < 0 || dot > n) return 0;
	int tmp = upper_bound(ALL(v[dot]) , vv) - v[dot].begin();
	return tmp * vv - sum[dot][tmp - 1];
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 2 , n + 1){
		if(i % 2 == 0) cin >> lv[i >> 1];
		if(i % 2 == 1) cin >> rv[i >> 1];
	}
	DFS(1);
	int a , b;
	REP(i , 1 , m + 1){
		cin >> a >> b;
		int ans = query(a , b);
		while(a != 1 && b >= 0){
			int dis;
			if(a % 2 == 0){
				dis = lv[a >> 1];
				ans += query(a + 1 , b - lv[a >> 1] - rv[a >> 1]);
			}
			if(a % 2 == 1){
				dis = rv[a >> 1];
				ans += query(a - 1 , b - lv[a >> 1] - rv[a >> 1]);
			}
			ans += max(0LL , b - dis);
			a = (a >> 1);
			b -= dis;
		}
		cout << ans << endl;
	}
    return 0;
}