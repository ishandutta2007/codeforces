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
#define INF 0x3f3f3f3f

int ans = 0 , x[100] , a[100];
int32_t main(){
    IOS;
    REP(i , 0 , 14) cin >> x[i];
    REP(p , 0 , 14){
    	REP(i , 0 , 14) a[i] = x[i];
    	int all = a[p];
    	a[p] = 0;
    	REP(i , 0 , 14) a[i] += all / 14;
    	all %= 14;
    	int now = (p + 1) % 14;
    	while(all) all -- , a[now] ++ , now = (now + 1) % 14;
    	int val = 0;
    	REP(i , 0 , 14) if(a[i] % 2 == 0) val += a[i];
    	ans = max(ans , val);
    }
    cout << ans << endl;
    return 0;
}