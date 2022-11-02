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
#define MAX 1000900
#define INF 0x3f3f3f3f

int use[MAX][2] , u[MAX];
int mod;
int x[2] , wnt[2] , tr[2][2];
PII cr[2];
int32_t main(){
    cin >> mod;
    cin >> x[0] >> wnt[0];
    cin >> tr[0][0] >> tr[0][1];
    cin >> x[1] >> wnt[1];
    cin >> tr[1][0] >> tr[1][1];
    REP(i , 0 , MAX) use[i][0] = use[i][1] = -1;

    REP(i , 0 , 2){
        int now = x[i] , cnt = 0;
        while(use[now][i] == -1){
            use[now][i] = cnt++;
            now = (now * tr[i][0] + tr[i][1]) % mod;
        }
        cr[i] = mp(use[now][i] , cnt - use[now][i]);
    }
    if(use[wnt[0]][0] == -1 || use[wnt[1]][1] == -1){
        cout << -1 << endl;
        return 0;
    }
    else if(use[wnt[0]][0] == use[wnt[1]][1]){
        cout << use[wnt[0]][0] << endl;
        return 0;
    }
    else {
        int ans = use[wnt[0]][0];
        int a = use[wnt[0]][0] , b = use[wnt[0]][0];
        if(b >= cr[1].A) b = (b - cr[1].A) % cr[1].B + cr[1].A;
        while(u[b] == 0){
            if(b == use[wnt[1]][1]){
                cout << ans << endl;
                return 0;
            }
            u[b] = 1;
            ans += cr[0].B;
            a += cr[0].B;
            if(a >= cr[0].A) a = (a - cr[0].A) % cr[0].B + cr[0].A;

            if(use[wnt[0]][0] != a){
                cout << -1 << endl;
                return 0;
            }

            b += cr[0].B;
            if(b >= cr[1].A) b = (b - cr[1].A) % cr[1].B + cr[1].A;
        }
        if(b == use[wnt[1]][1]){
            cout << ans << endl;
            return 0;
        }
        else cout << "-1" << endl;
    }
    return 0;
}