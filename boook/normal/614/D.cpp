#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200000
#define INF 0x3f3f3f3f

int n , mm , cf , cm , my;
int have[MAX] , pre[MAX] , ans[MAX] , good;
PII x[MAX];
int solve(int now){
    if(my < have[now]) return -1;
    int money = my - have[now] , nn = n - now;
    good = 0;
    RREP(i , 40 , 0){
        int tmp = good + (1LL << i);
        if(tmp > mm) continue;
        int qq = upper_bound(x , x + 1 + nn , mp(tmp , n + 10)) - x - 1;
        int need = tmp * qq - pre[qq];
        if(need <= money) good += (1LL << i);
    }
    if(now == n) good = mm;

    return good * cm + now * cf;
}
int32_t main(){
    cin >> n >> mm >> cf >> cm >> my;
    REP(i , 1 , n + 1) cin >> x[i].A , x[i].B = i;
    sort(x + 1 , x + n + 1);

    REP(i , 1 , n + 1) pre[i] = pre[i - 1] + x[i].A;
    int cnt = 1;
    RREP(i , n , 1)
        have[cnt] = have[cnt - 1] + mm - x[i].A , cnt ++;

    PII big = mp(0 , 0);
    REP(i , 0 , n + 1){
        int tmp = solve(i);
        if(tmp > big.A) big = mp(tmp , i);
    }
    solve(big.B);

    REP(i , 0 , big.B) ans[x[n - i].B] = mm , x[n - i].B = -1;
    REP(i , 1 , n + 1) if(x[i].B != -1){
        if(x[i].A < good) ans[x[i].B] = good;
        else ans[x[i].B] = x[i].A;
    }

    cout << big.A << endl;

    REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;

    return 0;
}