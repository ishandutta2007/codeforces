/*input
6 1
3 6 10 12 13 16
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , k , x[MAX] , cnt[MAX + 10];

int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) cnt[x[i]] ++;
    REP(i , 1 , MAX + 10) cnt[i] += cnt[i - 1];
    RREP(i , 1000000 , 1){
        if(cnt[i - 1] != 0) continue;
        if(i <= k) return cout << i << endl , 0;
        else {
            int res = 0;
            for(int j = i ; j < MAX ; j += i){
                int to = min(MAX-1 , j + k);
                res += cnt[to] - cnt[j - 1];
                // if(i == 3 && j < 100) DB4(to , j - 1 , cnt[to] - cnt[j - 1] , res);
            }
            if(res == n) return cout << i << endl , 0;
        }
    }
    return 0;
}