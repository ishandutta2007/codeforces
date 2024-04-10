#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 510
#define INF 0x3f3f3f3f

int n , m;
int x[MAX][MAX] , p[MAX][MAX];
VPII ans , fk , cc;
int32_t main(){
    int tmp = INF;
    cin >> n >> m;
    REPNM(i , 1 , n + 1){
        REPNM(j , 1 , m + 1){
            cin >> x[i][j];
            tmp = min(tmp , x[i][j]);
            p[i][j] = x[i][j];
        }
    }
    if(n > m){
        REP(times , tmp) REPNM(i , 1 , m + 1) cc.pb(mp(1 , i));
    }
    else {
        REP(times , tmp) REPNM(i , 1 , n + 1) cc.pb(mp(0 , i));
    }
    REPNM(i , 1 , n + 1){
        REPNM(j , 1 , m + 1){
            x[i][j] -= tmp;
        }
    }
    REPNM(i , 1 , n + 1){
        int ok = 1 , tma = INF;
        REPNM(j , 1 , m + 1){
            tma = min(tma , x[i][j]);
        }
        if(tma){
            REPNM(j , 1 , m + 1) x[i][j] -= tma;
            REP(times , tma) ans.pb(mp(0 , i));
        }
    }
    REPNM(j , 1 , m + 1){
        int ok = 1 , tma = INF;
        REPNM(i , 1 , n + 1){
            tma = min(tma , x[i][j]);
        }
        if(tma){
            REPNM(i , 1 , n + 1) x[i][j] -= tma;
            REP(times , tma) ans.pb(mp(1 , j));
        }
    }
    REPNM(j , 1 , m + 1){
        int ok = 1 , tma = INF;
        REPNM(i , 1 , n + 1){
            tma = min(tma , p[i][j]);
        }
        if(tma){
            REPNM(i , 1 , n + 1) p[i][j] -= tma;
            REP(times , tma) fk.pb(mp(1 , j));
        }
    }

    REPNM(i , 1 , n + 1){
        int ok = 1 , tma = INF;
        REPNM(j , 1 , m + 1){
            tma = min(tma , p[i][j]);
        }
        if(tma){
            REPNM(j , 1 , m + 1) p[i][j] -= tma;
            REP(times , tma) fk.pb(mp(0 , i));
        }
    }


    int ok = 1;
    REPNM(i , 1 , n + 1){
        REPNM(j , 1 , m + 1){
            if(x[i][j]) return puts("-1");
        }
    }
    int aa = ans.size() + cc.size();
    int bb = fk.size() + cc.size();
    if(aa < bb){
        cout << aa << endl;
        for(auto i : ans){
            if(i.A == 0) cout << "row " << i.B << endl;
            if(i.A == 1) cout << "col " << i.B << endl;
        }
        for(auto i : cc){
            if(i.A == 0) cout << "row " << i.B << endl;
            if(i.A == 1) cout << "col " << i.B << endl;
        }
    }
    else {
        cout << bb << endl;
        for(auto i : fk){
            if(i.A == 0) cout << "row " << i.B << endl;
            if(i.A == 1) cout << "col " << i.B << endl;
        }   
        for(auto i : cc){
            if(i.A == 0) cout << "row " << i.B << endl;
            if(i.A == 1) cout << "col " << i.B << endl;
        }
    }
    return 0;
}