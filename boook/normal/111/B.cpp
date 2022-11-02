/*input

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
#define MAX 100500
#define INF 0x3f3f3f3f

int n , big[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1){
		int val , kth , ans = 0;
		cin >> val >> kth;
		REP(j , 1 , val + 1){
			if(j * j > val) break;
			else if(j * j == val){
				if(big[j] < i - kth) ans ++;
			}
			else if(val % j == 0){
				if(big[j] < i - kth) ans ++;
				if(big[val / j] < i - kth) ans ++;
			}
		}
		REP(j , 1 , val + 1){
			if(j * j > val) break;
			if(val % j == 0) big[j] = big[val / j] = i;
		}
		cout << ans << endl;
	}	
    return 0;
}