/*input
2 1 2
0 1
0
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , k;
int a[MAX] , b[MAX] , sol[MAX];
int cmp(int q , int w){
    return b[q] > b[w];
}
int judge(int now){
    int apo = 1 , bpo = now , val;
    REP(i , 0 , n + now){
        if(apo == n + 1) val = b[sol[bpo --]];
        else if(bpo == 0) val = a[apo ++];
        else if(a[apo] <= b[sol[bpo]]) val = a[apo ++];
        else if(a[apo] >= b[sol[bpo]]) val = b[sol[bpo --]];
        // DB4("val = " , val , apo , bpo);
        if(i / k <= val);
        else return 0;
    }
    return 1;
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , m + 1) cin >> b[i];
    REP(i , 1 , m + 1) sol[i] = i;
    sort(a + 1 , a + 1 + n);
    sort(sol + 1 , sol + 1 + m , cmp);
    int ans = 0;
    if(judge(0) == 0) cout << -1 << endl;
    else {
        int ans = 0;
        RREP(i , 20 , 0){
            int to = ans + (1 << i);
            if(to <= m && judge(to)){
                ans = to;
            }
        }
        judge(ans);
        cout << ans << endl;
        REP(i , 1 , ans + 1) cout << sol[i] << " " ; cout << endl;
    }
    return 0;
}