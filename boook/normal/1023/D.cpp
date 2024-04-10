/*input
5 6
5 5 0 5 5
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
#define MAX 200900
#define INF 0x3f3f3f3f


int n , m , x[MAX] , ans[MAX];
int sml[MAX] , big[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;    
    REP(i , 1 , n + 1) cin >> x[i];
    MEM(sml , INF) , MEM(big , 0);
    REP(i , 1 , n + 1){
        sml[x[i]] = min(sml[x[i]] , i);
        big[x[i]] = max(big[x[i]] , i);
    }
    MEM(ans , -1);
    if(sml[m] == INF){
        int idx = -1;
        REP(i , 1 , n + 1) if(x[i] == 0) idx = i;
        if(idx == -1) return cout << "NO" << endl , 0;
        sml[m] = big[m] = idx;
        x[idx] = m;
    }
    int ok = 0;
    RREP(i , m , 1) if(sml[i] != INF){
        ok = 1;
        int now = sml[i];
        while(now <= big[i]){
            if(ans[now] != -1) now = big[ans[now]] + 1;
            else ans[now] = i , now ++;
        }
    }
    // REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    REP(i , 1 , n + 1) if(x[i] != 0 && x[i] != ans[i]) return cout << "NO" << endl , 0;
    if(ok == 0){
        cout << "YES" << endl;
        REP(i , 1 , n + 1) cout << m << " " ; cout << endl;
    }
    else {
        REP(i , 1 , n + 1) if(ans[i] == -1 && ans[i - 1] != -1) ans[i] = ans[i - 1];
        RREP(i , n , 1)    if(ans[i] == -1 && ans[i + 1] != -1) ans[i] = ans[i + 1];
        cout << "YES" << endl;
        REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    }
    return 0;
}