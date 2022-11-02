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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 200
#define INF 0x3f3f3f3f

int sml = INF , ans[MAX] , mm[MAX];
int n , g[MAX][MAX];
PII x[MAX];
vector<int> v;
void DFS(int now){
    if(now == 60){
        vector<int> vv = v;
        int tmp = 0;
        REP(i , 1 , n + 1){
            if(vv.size() == 0) tmp += x[i].A - 1 , mm[x[i].B] = 1;
            else tmp += abs(x[i].A - vv.back()) , mm[x[i].B] = vv.back() , vv.pop_back();
            if(tmp > sml) return ;
        }
        if(tmp < sml){
            sml = tmp;
            REP(i , 1 , n + 1){
                ans[i] = mm[i];
            }
        }
    }
    else {
        int ok = 1;
        for(auto to : v){
            if(g[to][now] != 1){
                ok = 0;
                break;
            }
        }
        if(ok){
            v.push_back(now);
            DFS(now + 1);
            v.pop_back();
        }
        DFS(now + 1);
    }
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , 70) REP(j , 1 , 70) g[i][j] = __gcd(i , j);
    REP(i , 1 , n + 1){
        cin >> x[i].A , x[i].B = i;
    }
    sort(x + 1 , x + 1 + n , greater<PII>());
    v.pb(1);
    DFS(2);
    REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}