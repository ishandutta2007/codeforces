/*input
68
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int judge(int n , int k){
	int cnt = 0;
	while(n){
		cnt += min(k , n);
		n -= min(k , n);
		n -= n / 10;
	}
	return cnt;
}
int n;
int32_t main(){
	IOS;
	cin >> n;
	int ans = n;
	RREP(i , 63 , 0){
		int to = ans - (1LL << i);
		if(to >= 1 && judge(n , to) * 2 >= n) ans = to;
	}
	cout << ans << endl;
    return 0;
}