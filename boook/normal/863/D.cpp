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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX] , a[MAX][3];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , m + 1) REP(j , 0 , 3) cin >> a[i][j];
    REP(times , 1 , k + 1){
        int now; cin >> now;
        RREP(i , m , 1){
            int l = a[i][1] , r = a[i][2];
            if(l <= now && now <= r){
                if(a[i][0] == 1){
                    if(now == l) now = r;
                    else now = now - 1;
                }
                else {
                     now = r - l - (now - l) + l;
                }
            }
        }

        cout << x[now] << " ";
    }
    cout << endl;
    return 0;
}