/*input
4
6 8 4 4
16 22 10 10
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , c[MAX] , v1[MAX] , v2[MAX] , p[MAX];

int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	int sum = 0;
	REP(i , 1 , n + 1) sum += a[i] + b[i];
	REP(i , 1 , n + 1) c[i] = (a[i] + b[i] - sum / 2 / n) / n;

	REP(i , 0 , 30){
		int base = (1 << i);
		REP(j , 1 , n + 1) p[j] = p[j - 1] + ((c[j] & base) ? 1 : 0);
		REP(j , 1 , n + 1){
			if((c[j] & base) == 0){
				v2[j] += base * p[n];
			}
			if((c[j] & base) != 0){
				v1[j] += base * p[n];
				v2[j] += base * n;
			}
		}
	}
	REP(i , 1 , n + 1) if(v1[i] != a[i]) return cout << -1 << endl , 0;
	REP(i , 1 , n + 1) if(v2[i] != b[i]) return cout << -1 << endl , 0;
	REP(i , 1 , n + 1) cout << c[i] << " ";cout << endl;
    return 0;
}