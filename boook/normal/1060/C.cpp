/*input
5 1
5 4 2 4 5
2
5
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
#define MAX 2020
#define INF 100000000000000LL

int n , m , a[MAX] , b[MAX] , p[MAX] , bst[MAX] , sum[MAX] , lim;
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , m + 1) cin >> b[i];
    cin >> lim;
    REP(i , 1 , m + 1) p[i] = p[i - 1] + b[i];
    REP(i , 1 , m + 1) bst[i] = INF;
    REP(i , 1 , m + 1) REP(j , i , m + 1) bst[j - i + 1] = min(bst[j - i + 1] , p[j] - p[i - 1]);


    REP(i , 1 , n + 1) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    REP(i , 1 , n + 1) REP(j , i , n + 1){
        int val = sum[j] - sum[i - 1];
        int goal = lim / val , now = 0;
        RREP(bit , 12 , 0){
            int to = now + (1 << bit);
            if(to <= m && bst[to] <= goal) now = to;
        }
        ans = max(ans , now * (j - i + 1));
    }
    cout << ans << endl;
    return 0;
}