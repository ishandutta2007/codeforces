
 /*input
2 2 2 1

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

int a , b , c , d;
int32_t main(){
    IOS;
    cin >> a >> b >> c >> d;
    int aa = a - c , bb = b - c;
    if(aa < 0 || bb < 0 || a == d || b == d || aa == d || bb == d) cout << -1 << endl;
    else{

        int ans = d - aa - bb - c;
        if(ans <= 0 || aa + bb + c > d) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}