/*input
7
1 2 1 1 1 3 2
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , c[MAX] , ufr[MAX] , uba[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];

    MEM(c , 0);
    REP(i , 1 , n + 1){
        if(c[x[i]]) ufr[i] = 0;
        else ufr[i] = 1;
        c[x[i]] = 1;
    }
    MEM(c , 0);
    RREP(i , n , 1){
        if(c[x[i]]) uba[i] = 0;
        else uba[i] = 1;
        c[x[i]] = 1;
    }
    RREP(i , n , 1) uba[i] += uba[i + 1];
    int ans = 0;
    REP(i , 1 , n + 1) if(ufr[i] == 1) ans += uba[i + 1];
    cout << ans << endl;
    return 0;
}