#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1090
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	cin >> n;
	REP(i , 0 , n) cin >> x[i];
	int ans = 0;
	while(1){
		int mm = x[1];
		REP(i , 1 , n) mm = max(mm , x[i]);
		if(x[0] > mm) break;
		REP(i , 1 , n){
			if(x[i] == mm){
				x[i] -- , x[0] ++ , ans ++;
				break;
			}
		}
	}
	cout << ans << endl;
    return 0;
}