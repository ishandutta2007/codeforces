/*input
4
54
50
2
178
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
#define MAX 200
#define INF 0x3f3f3f3f

int ans[MAX];
int32_t main(){
	IOS;
	REP(idx , 1 , 180 + 1){
		// idx = 2;
		REP(i , 3 , MAX * MAX){
			// i = 90;

			if(180 * (i - 2) >= idx * i){
				// cout << "here" << endl;
				if(idx * i >= 180){
					int tmp = idx * 2 * i / 360;
					// DBGG("tmp = " , tmp);
					if(360 * tmp % (i + i) == 0 && 360 * tmp / (i + i) == idx){
						ans[idx] = i;
						// cout << "jere" << endl;
						break;
					}
				}
			}
			// return 0;
		}
		// return 0;
	}
	int t , in;
	cin >> t;
	REP(i , 0 , t){
		cin >> in;
		cout << ans[in] << endl;
	}
    return 0;
}