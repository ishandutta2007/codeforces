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
#define MAX 3000900
#define INF 0x3f3f3f3f

int n , x[MAX] , val[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1){
		cin >> x[i];
		val[x[i]] = x[i];
	}
	sort(x + 1 , x + 1 + n);
	n = unique(x + 1 , x + 1 + n) - x - 1;
	REP(i , 1 , MAX) val[i] = max(val[i - 1] , val[i]);
	int ans = 0;
	REP(i , 1 , n + 1){
		int fr = x[i] , ba = x[i] + x[i] - 1;
		while(ba < MAX){
			if(val[ba] >= x[i]) ans = max(ans , val[ba] % x[i]);
			ba += x[i];
		}
	}
	cout << ans << endl;
    return 0;
}