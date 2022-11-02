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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX][2] , sol[MAX];
int u[MAX] , r[MAX] , vu[MAX] , vr[MAX];
cc_hash_table<int , int> cc;
int MP(int a , int b){
	return a * 1000000007 + b;
}
int cmp1(int a , int b){ 
	if(x[a][0] != x[b][0]) return x[a][0] < x[b][0]; 
	else return x[a][1] < x[b][1];
}
int cmp2(int a , int b){
	if(x[a][1] != x[b][1]) return x[a][1] < x[b][1];
	else return x[a][0] < x[b][0];
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	REP(i , 1 , n + 1) sol[i] = i;
	
	sort(sol + 1 , sol + 1 + n , cmp1);
	REP(i , 1 , n + 0) if(x[sol[i]][0] == x[sol[i + 1]][0]) u[sol[i]] = sol[i + 1];
	RREP(i , n , 1) vu[sol[i]] = vu[u[sol[i]]] + 1;
	
	sort(sol + 1 , sol + 1 + n , cmp2);	
	REP(i , 1 , n + 0) if(x[sol[i]][1] == x[sol[i + 1]][1]) r[sol[i]] = sol[i + 1];
	RREP(i , n , 1) vr[sol[i]] = vr[r[sol[i]]] + 1;
	
	REP(i , 1 , n + 1) cc[MP(x[i][0] , x[i][1])] = 1;
	int ans = 0;
	REP(i , 1 , n + 1){
		if(vu[i] < vr[i]){
			int now = u[i];
			while(now != 0){
				int len = x[now][1] - x[i][1];
				if(cc.find(MP(x[i][0] + len , x[i][1])) != cc.end() && 
				 cc.find(MP(x[now][0] + len , x[now][1])) != cc.end()) ans ++;
				now = u[now];
			}
		}
		else {
			int now = r[i];
			while(now != 0) {
				int len = x[now][0] - x[i][0];
				if(cc.find(MP(x[i][0] , x[i][1] + len)) != cc.end() && 
				cc.find(MP(x[now][0] , x[now][1] + len)) != cc.end()) ans ++;
				now = r[now];
			}
		}
	}
	cout << ans << endl;
    return 0;
}