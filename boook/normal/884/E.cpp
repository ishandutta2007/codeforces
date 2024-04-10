/*input
3 8
1F
AE
3C
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
#define MAX 40384
#define INF 0x3f3f3f3f

int n , m , po = 0 , x[MAX] , id[MAX] , tmp[MAX] , use[MAX];
int Find(int now){
    return now == tmp[now] ? now : tmp[now] = Find(tmp[now]);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    int ans = 0;
    REP(i , 1 , n + 1){
        for(int j = 1 ; j <= m ; j += 4){
            char c;
            cin >> c;
            int val = 0;
            if('0' <= c && c <= '9') val = c - '0';
            else val = c - 'A' + 10;
            x[j + 3] = val % 2 , val >>= 1;
            x[j + 2] = val % 2 , val >>= 1;
            x[j + 1] = val % 2 , val >>= 1;
            x[j + 0] = val % 2 , val >>= 1;
        }
        // REP(j , 1 , m + 1){
        //     cout << x[j] << " ";
        // }cout << endl;
        REP(j , 1 , m + 1) tmp[j] = 0 , use[j] = 0;
        REP(j , 1 , m + 1){
            if(x[j] && id[j]){
                if(use[id[j]]) tmp[j] = use[id[j]];
                else tmp[j] = use[id[j]] = j;
            }
        }
        RREP(j , m , 1){
            if(x[j] && tmp[j] == 0 && tmp[j + 1]) tmp[j] = tmp[j + 1];
        }
        REP(j , 1 , m + 1){
            if(x[j] && tmp[j] == 0 && tmp[j - 1]) tmp[j] = tmp[j - 1];
        }
        REP(j , 1 , m + 1){
            if(tmp[j] && tmp[j + 1]){
                int a = Find(j) , b = Find(j + 1);
                if(a != b) ans -- , tmp[a] = b;
            }
        }
        REP(j , 1 , m + 1){
            tmp[j] = Find(tmp[j]);
        }
        REP(j , 1 , m + 1){
            if(x[j] && tmp[j] == 0 && tmp[j - 1]) tmp[j] = tmp[j - 1];
            if(x[j] && tmp[j] == 0) tmp[j] = j , ans ++;
        }
        REP(j , 1 , m + 1){
            id[j] = tmp[j];
        }
        // REP(j , 1 , m + 1) cout << id[j] << " ";DBGG(" = id , po = " , ans);
    }
    cout << ans << endl;
    return 0;
}