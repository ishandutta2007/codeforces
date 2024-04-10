/*input
1 2
1
1
2
2
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 200
#define INF 0x3f3f3f3f

struct N{
    int id , x , y;
};
vector<N> ans;
int n , k , in , a[MAX] , aa[MAX] , b[MAX] , bb[MAX] , u[MAX];
PII x[MAX] , wt[MAX];
int can(int now){
    if(abs(wt[now].A - x[now].A) == 1 && wt[now].B == x[now].B){
    //     DBGG("now = " , now);
    // DBGG(wt[now].A , wt[now].B);
    // DBGG(x[now].A , x[now].B);
    // exit(0);
        ans.pb(N{now , wt[now].A , wt[now].B});
        u[now] = 1;
        return 1;
    }
    else return 0;
}
int put(int idx , PII now){
    // DB4("why = " , now.A , now.B , "");
    REP(i , 1 , k + 1) if(u[i] == 0 && x[i] == now) return 0;
    x[idx] = now;
    ans.pb(N{idx , now.A , now.B});

    // cout << "fack" << endl;
    // for(auto to : ans) cout << to.id << " " << to.x << " " << to.y << endl;
    return 1;
}
int solve(int now){
    // cout << "here" << endl;
    // cout << x[now].A << " " << x[now].B << endl;
    if(x[now].A == 2){
        if(x[now].B == 1){
            if(put(now , mp(3 , 1))) return 1;
        }
        else if(put(now , mp(2 , x[now].B - 1))) return 1;
    }
    if(x[now].A == 3){
        if(x[now].B == n){
            if(put(now , mp(2 , n))) return 1;
        }
        else if(put(now , mp(3 , x[now].B + 1))) return 1;
    }
    return 0;
}
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 1 , n + 1) cin >> a[i] , wt[a[i]] = mp(1 , i);
    REP(i , 1 , n + 1) {
        cin >> in , aa[i] = in;
        if(in != 0) x[in] = mp(2 , i);
    }
    REP(i , 1 , n + 1){
        cin >> in , bb[i] = in;
        if(in != 0) x[in] = mp(3 , i);
    }
    REP(i , 1 , n + 1) cin >> b[i] , wt[b[i]] = mp(4 , i);

    vector<int> sol;
    REP(i , 1 , n + 1) if(aa[i] != 0) sol.pb(aa[i]);
    RREP(i , n , 1)    if(bb[i] != 0) sol.pb(bb[i]);

    int ok = 0;
    // REP(i , 1 , k + 1) DBGG(x[i].A , x[i].B);
    // return 0;
    while(ok != k){
        REP(i , 1 , k + 1) if(u[i] == 0 && can(i)) u[i] = 1 , ok ++;
        int move = 0 , pos = 0;
        while(move != k - ok){
            if(u[sol[pos]] == 1) pos = (pos + 1) % sol.size();
            else {
                if(solve(sol[pos])) move ++;
                pos = (pos + 1) % sol.size();
            }
    // for(auto to : ans) cout << to.id << " " << to.x << " " << to.y << endl;
    //     return 0;
    //      if(pos == 0 && move == 0){
    //          return cout << -1 << endl , 0;
    //      }
            if(pos == 0 && move == 0) return cout << -1 << endl , 0;
        }
    }
    cout << ans.size() << endl;
    for(auto to : ans) cout << to.id << " " << to.x << " " << to.y << endl;
    return 0;
}