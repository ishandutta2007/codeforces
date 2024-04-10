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
#define MAX 400000
#define INF 0x3f3f3f3f

int n , m;
int x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i] , x[i] ^= 1;
    PII ans = mp(0 , 0);
    int r = 0 , val = 0;
    REP(l , 1 , n + 1){
        while(r + 1 <= n && val + x[r + 1] <= m){
            val += x[r + 1];
            r ++;
        }
        ans = max(ans , mp(r - l + 1 , l));
        val -= x[l];
    }
    cout << ans.A << endl;
    REP(i , 0 , ans.A){
        x[ans.B + i] = 0;
    }
    REP(i , 1 , n + 1) cout << 1 - x[i] << " "; cout << endl;
    return 0;
}