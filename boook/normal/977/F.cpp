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
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX] , v[MAX] , dp[MAX];
map<int , int> cc;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    RREP(i , n , 1){
    	if(cc.find(x[i] + 1) != cc.end()) v[i] = cc[x[i] + 1];
    	cc[x[i]] = i;
    }
    int big = 0 , from = 0;
    RREP(i , n , 1){
    	if(v[i] == 0) dp[i] = 1;
    	else dp[i] = dp[v[i]] + 1;
    	if(dp[i] > big) big = dp[i] , from = i;
    }
    cout << big << endl;
    REP(i , 0 , big){
    	cout << from << " ";
    	from = v[from];
    }
    cout << endl;
    return 0;
}