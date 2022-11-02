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
#define int long long
#define MAX 200900
#define INF 6000000000000000LL

int n , k , x[MAX] , hh[MAX] , suf[MAX];

int32_t main(){
    cin >> n >> k;
    RREP(i , n , 0) cin >> x[i];
    int tmp = 0 , ok = n;
    RREP(i , n , 0){
        hh[i] = tmp - x[i];
        if(hh[i] % 2 == 0){
            tmp = hh[i] / 2;
            if(i) suf[i - 1] = tmp , ok = i - 1;
        }
        else break;
    }

    // REP(i , 0 , n + 1)
    //     cout << suf[i] << " " ; cout << endl;
    // cout << "-----------" << ok << endl;

    int val = 0 , ans = 0;
    REP(i , 0 , n + 1){
        // DBGG("-----" , val);
        if(i >= ok){
            if(abs(suf[i] - val) <= k){
                if(suf[i] - val == 0 && i == 0);
                else ans ++;
                // DBGG("find one = " , suf[i] - val);
            }
        }
        val = (x[i] + val) * 2;
        if(abs(val) > INF) break;
    }
    cout << ans << endl;
    return 0;
}