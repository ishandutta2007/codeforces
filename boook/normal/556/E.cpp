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
#define MAX 200070
#define INF 0x3f3f3f3f

int n , m , ans[MAX];
PII x[MAX];
void solve(int l , int r){
    if(l == r) return ;
    int mid = ((l + r) >> 1);
    solve(l , mid);

    vector<PII> lthing;
    vector<PII> now;
    REP(i , mid + 1 , r + 1){
        if(x[i].B == 1) now.pb(mp(x[i].A , i));
    }
    sort(ALL(now));
    REP(i , l , mid + 1){
        if(x[i].B == 0 && ans[i] > 0){
            lthing.pb(mp(x[i].A , x[i].A));
            lthing.pb(mp(x[i].A + ans[i] , -x[i].A));
            // DBGG(x[i].A , x[i].A);
            // DBGG(x[i].A + ans[i] , -x[i].A);
        }
    }
    sort(ALL(lthing));
    int po = 0;
    multiset<int> cc;
    REP(i , 0 , now.size()){
        while(po < lthing.size() && lthing[po].A <= now[i].A){
            if(lthing[po].B > 0) cc.insert(lthing[po].B);
            else cc.erase(cc.find(-lthing[po].B));
            po ++;
        }
        if(cc.size()){
            auto tmp = cc.end(); tmp --;
            ans[now[i].B] = min(ans[now[i].B] , x[now[i].B].A - ((*tmp) + 1) + 1);
        }
    }

    lthing.clear() , now.clear() , cc.clear();

    REP(i , mid + 1 , r + 1){
        if(x[i].B == 0) now.pb(mp(x[i].A , i));
    }
    sort(ALL(now));
    REP(i , l , mid + 1){
        if(x[i].B == 1 && ans[i] > 0){
            lthing.pb(mp(x[i].A - ans[i] + 1 , n - x[i].A));
            lthing.pb(mp(x[i].A + 1 , -(n - x[i].A)));
        }
    }
    sort(ALL(lthing));
    po = 0;
    REP(i , 0 , now.size()){
        while(po < lthing.size() && lthing[po].A <= now[i].A){
            if(lthing[po].B > 0) cc.insert(lthing[po].B);
            else cc.erase(cc.find(-lthing[po].B));
            po ++;
        }
        if(cc.size()){
            auto tmp = cc.end(); tmp --;
            int val = (n - now[i].A) - ((*tmp) + 1) + 1;
            ans[now[i].B] = min(ans[now[i].B] , val);
        }
    }
    // DB4("now at " , l , r , "");
    // REP(i , 0 , m) cout << ans[i] << " "; cout << endl;
    solve(mid + 1 , r);
}
set<int> use;
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , m){
        string c;
        cin >> x[i].A >> x[i].B >> c;
        if(c[0] == 'U') ans[i] = x[i].B , x[i].B = 0;
        if(c[0] == 'L') ans[i] = x[i].A , x[i].B = 1;
    }
    REP(i , 0 , m){
        if(use.find(x[i].A) != use.end()) ans[i] = 0;
        use.insert(x[i].A);
    }
    n ++;
    solve(0 , m - 1);
    REP(i , 0 , m) cout << ans[i] << endl;
    return 0;
}