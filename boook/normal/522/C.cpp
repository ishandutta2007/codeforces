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
#define MAX 100900
#define INF 0x3f3f3f3f

int t , n , m , x[MAX] , ans[MAX];

int32_t main(){
    IOS;
    cin >> t;
    REP(times , 0 , t){
        cin >> n >> m;
        REP(i , 1 , m + 1) cin >> x[i];
        MEM(ans , 0);
        int q , w , po = 0 , cnt = 0 , bacnt = 0;
        set<int> cc;
        REP(i , 1 , n){
            cin >> q >> w;
            if(po == 1 || w == 1){
                if(po == 0){
                    REP(j , 1 , m + 1) if(x[j] <= cnt) cc.insert(j);
                }

                po = 1;
                if(q != 0) x[q] -- , cc.erase(q);
                else bacnt ++;
            }
            else {
                if(q != 0) x[q] --;
                else cnt ++;
            }
        }
        if(po == 1){
            int tmp = INF;
            for(auto now : cc) tmp = min(tmp , x[now]) , ans[now] = 1;
            cnt -= tmp;
        }
        // DBGG("cnt = " , cnt);
        REP(i , 1 , m + 1)
            if(cnt + bacnt >= x[i]) ans[i] = 1;

        REP(i , 1 , m + 1){
            cout << ((ans[i] == 0) ? "N" : "Y");
        }cout << endl;
    }
    return 0;
}