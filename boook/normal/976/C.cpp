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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f

int n , sol[MAX];
PII x[MAX];
int cmp(int a , int b){
	if(x[a].A == x[b].A) return x[a].B > x[b].B;
	if(x[a].A != x[b].A) return x[a].A < x[b].A;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
   	REP(i , 1 , n + 1) sol[i] = i;
   	sort(sol + 1 , sol + 1 + n , cmp);
   	int big = INF , id = -1;
    RREP(idx , n , 1){
    	int i = sol[idx];
    	if(x[i].B >= big){
    		cout << id << " " << i << endl;
    		return 0;
    	}
    	if(x[i].B < big) big = x[i].B , id = i;
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}