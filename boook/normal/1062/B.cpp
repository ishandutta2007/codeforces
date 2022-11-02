/*input
1000000
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
#define MAX 
#define INF 0x3f3f3f3f

int n;
int32_t main(){
	IOS;
	cin >> n;
	map<int , int> cc;
	REP(i , 2 , n + 1){
		while(n % i == 0) cc[i] += 1 , n /= i;
	}
	int ok = 1 , base = 1 , big = 0 , sml = INF;
	for(auto to : cc) base *= to.A , ok = to.B == 1 ? ok : 0;

	for(auto to : cc) sml = min(sml , to.B);
	for(auto to : cc) big = max(big , to.B);

	if(ok) cout << base << " 0" << endl;
	else {
		int cnt = 0;
		while((1 << cnt) < big) cnt ++;
		cout << base << " " << cnt + (sml != (1 << cnt) || big != (1 << cnt)) << endl;
	}
    return 0;
}