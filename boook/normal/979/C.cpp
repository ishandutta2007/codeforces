#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f

int n , x , y , no;
vector<int> v[MAX];
PII DFS(int now , int fa){
	if(now == no) return mp(0 , 0);
	int can = 1 , sum = 0;
	for(auto to : v[now]) if(to != fa){
		PII tmp = DFS(to , now);
		if(tmp.A == 0) can = 0;
		else sum += tmp.B;
	}
	return mp(can , sum + can);
}
int32_t main(){
    IOS;
    cin >> n >> x >> y;
    REP(i , 1 , n + 0){
    	int a , b;
    	cin >> a >> b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    no = y;
    int v1 = DFS(x , 0).B + 1;
    no = x;
    int v2 = DFS(y , 0).B + 1;
    int all = n * (n - 1);
    // DBGG(v1 , v2);
    cout << all - v1 * v2 << endl;
    return 0;
}