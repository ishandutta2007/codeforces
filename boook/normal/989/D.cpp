/*input
4 10 1
-20 1
-10 -1
0 1
10 -1
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX][2];
int can(int a , int b){
    if(a == b) return 0;
    // val = (a + b) / (b - a)
    return (a + b < (b - a) * k);
}

vector<int> v1 , v2 , v3 , v4;
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];

    int ltor = 0 , rtol = 0;
    REP(i , 1 , n + 1){
        if(x[i][1] ==  1 && x[i][0] < 0) ltor ++;
        if(x[i][1] == -1 && x[i][0] + m > 0) rtol ++;
    }
    int ans = ltor * rtol;
    REP(i , 1 , n + 1){
        if(x[i][1] == -1 && x[i][0] + m <= 0) v2.pb(abs(x[i][0] + m));
        if(x[i][1] ==  1 && x[i][0] + m <= 0) v3.pb(abs(x[i][0]));
        

        if(x[i][1] ==  1 && x[i][0] >= 0) v1.pb(x[i][0]);
        if(x[i][1] == -1 && x[i][0] >= 0) v4.pb(x[i][0] + m);
    }
    sort(ALL(v1));
    sort(ALL(v2));
    sort(ALL(v3));
    sort(ALL(v4));
    // for(auto to : v1) cout << to << " "; cout << endl;
    // for(auto to : v4) cout << to << " "; cout << endl;

    //     cout << can(2 , 4) << endl;
    for(auto now : v1){
        int to = lower_bound(ALL(v4) , now) - v4.begin() , base = v4.size();
        if(to == v4.size()) break;
        else if(can(now , v4[to]) == 1) ans += base - to;
        else {
            RREP(j , 20 , 0){
                int tmp = to + (1 << j);
                if(tmp < v4.size() && can(now , v4[tmp]) == 0) to = tmp;
            }to ++;
            ans += base - to;
        }
    }
    for(auto now : v2){
        int to = lower_bound(ALL(v3) , now) - v3.begin() , base = v3.size();
        if(to == v3.size()) break;
        else if(can(now , v3[to]) == 1) ans += base - to;
        else {
            RREP(j , 20 , 0){
                int tmp = to + (1 << j);
                if(tmp < v3.size() && can(now , v3[tmp]) == 0) to = tmp;
            }to ++;
            ans += base - to;
        }
    }
    // for(auto now : v2){
    //     int to = lower_bound(ALL(v3) , to) - v3.begin() , base = to;
    //     if(to == v3.size() || can(now , v3[to]) == 0) break;
    //     else {
    //         RREP(j , 20 , 0){
    //             int tmp = to + (1 << j);
    //             if(tmp < v3.size() && can(now , v3[tmp])) to = tmp;
    //         }
    //         ans += to - base + 1;
    //     }
    // }

    cout << ans << endl;
    return 0;
}