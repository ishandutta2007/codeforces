/*input
2
1
2
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
#define MAX 1000
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];

	if(x[1] != 1 && x[1] != 2) return cout << "NO" << endl , 0;
	int a = 1 , b = 2 , other = 3;
	REP(i , 1 , n + 0){
		if(x[i] == a) swap(b , other);
		if(x[i] == b) swap(a , other);
		if(x[i + 1] == other) return cout << "NO" << endl , 0;
	}
	cout << "YES" << endl;
    return 0;
}