/*input
8 8
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
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
#define MAX 10000
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX];
set<int> aa , bb;
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i] , aa.insert(a[i]);
	REP(i , 1 , m + 1) cin >> b[i] , bb.insert(b[i]);
	REP(i , 1 , INF){
		int v1 = 0 , v2 = 0 , val = i;
		while(val){
			if(aa.count(val % 10)) v1 = 1;
			if(bb.count(val % 10)) v2 = 1;
			val /= 10;
		}
		if(v1 && v2) return cout << i << endl , 0;
	}
    return 0;
}