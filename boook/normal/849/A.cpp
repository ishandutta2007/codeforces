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
#define MAX 100000
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    if(x[1] % 2 == 0 || x[n] % 2 == 0)
    	return cout << "No" << endl , 0;
    if(n % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}