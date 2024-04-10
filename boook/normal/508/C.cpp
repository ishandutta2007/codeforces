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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , k;
int x[MAX] , bit[MAX] , cnt[MAX];
void update(int from){
    from += 1000;
    for(int i = from ; i < MAX ; i += i & -i)
        bit[i] += 1;
}
int query(int from){
    from += 1000;
    int res = 0;
    for(int i = from ; i > 0 ; i -= i & -i){
        res += bit[i];
    }
    return res;
}
int Find(int l , int r){
    return query(r) - query(l - 1);
}
int32_t main(){
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    if(m < k) cout << -1 << endl;
    else {
        int ans = 0;
        REP(i , 1 , n + 1){
            int r = x[i] , l = x[i] - m + 1;
            if(Find(l , r) >= k) continue;
            else {
                int qq = Find(l , r);
                RREP(j , x[i] , x[i] - m + 1){
                    if(cnt[j + 1000] == 0){
                        qq ++ , update(j) , ans ++ , cnt[j + 1000] = 1;
                        // DBGG("nwo = " , j);
                    }
                    if(qq == k) break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}