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
#define MAX 
#define INF 0x3f3f3f3f

int n;
int judge(int now){
	int cnt = 0;
	REP(i , 2 , now + 1){
		cnt += now / i / i / i;
		if(now / i / i / i == 0) break;
	}
	return cnt;
}
int32_t main(){
	IOS;
	cin >> n;    
	int ans = 0;
	RREP(i , 55 , 0){
		int to = ans + (1LL << i);
		if(judge(to) < n) ans = to;
	} ans ++;
    if(judge(ans) != n) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}