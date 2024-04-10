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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m;
PII x[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , m + 1) cin >> x[i].A >> x[i].B;
    int ans = x[1].B;
    REP(i , 2 , m + 1){
        int tmp = x[i - 1].B , day = x[i].A - x[i - 1].A;
        int big = tmp + day , sml = max(0LL , tmp - day);
        if(sml <= x[i].B && x[i].B <= big){
            int now = sml;
            RREP(j , 40 , 0){
                int to = now + (1LL << j);
                if(abs(to - tmp) + abs(to - x[i].B) <= day) now = to;
            }
            ans = max(ans , now);
        }
        else {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    ans = max(ans , x[1].B + x[1].A - 1);
    ans = max(ans , n - x[m].A + x[m].B);
    cout << ans << endl;
    return 0;
}