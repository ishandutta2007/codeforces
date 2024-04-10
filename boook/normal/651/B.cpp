/*input
4
200 100 100 200
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
#define MAX 2000
#define INF 0x3f3f3f3f

int n , tmp , use[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1){
        cin >> tmp;
        use[tmp] ++;
    }
    int cnt = 0;

    while(1){
        int val = 0;
        REP(i , 1 , 1001){
            if(use[i]) use[i]-- , val ++;
        }
        if(val == 0) break;
        else cnt += val - 1;
    }
    cout << cnt << endl;
    return 0;
}