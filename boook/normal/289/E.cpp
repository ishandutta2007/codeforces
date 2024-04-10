/*input
4
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

int n , x[MAX];
int solve(int val){
	int tmp = 0 , ans = 0;
	REP(i , 0 , 21) 
		if(val & (1 << i)) tmp = i;
	REP(i , 0 , tmp) 
		if(val & (1 << i));
		else ans |= (1 << i);
	return ans;
}
int32_t main(){
    IOS;
    cin >> n;
    int to = solve(n) , nn = n;
    while(1){
    	int fr = to , ba = n;
    	while(fr <= ba) x[fr] = ba , x[ba] = fr , fr ++ , ba --;
    	if(to == 0) break;
    	else n = to - 1 , to = solve(n);
    }
    int ans = 0;
    REP(i , 0 , nn + 1) ans += i ^ x[i];
    cout << ans << endl;
    REP(i , 0 , nn + 1) cout << x[i] << " " ; cout << endl;
    return 0;
}