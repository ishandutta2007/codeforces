#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define PII pair<int , int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX];
vector<int> ans;
int calc(int l , int r){
    int v1 = l + r;
    int v2 = (r - l) / 2 + 1;
    return v1 * v2 / 2;
}
int32_t main(){
    IOS;
    cin >> n , n /= 2;
    REP(i , 1 , n + 1) cin >> x[i];
    
    int pre = 0 , use = 1;
    REP(i , 1 , n + 1){
        if(x[i] % 2 == 0 && x[i] % 4 != 0) return cout << "No" << endl , 0;
//        cout << "i = " << i << " " << "use = " << use << endl;
        PII can = mp(INF , INF);
        REP(j , 1 , MAX){
            if(j * j > x[i]) break;
            else if(x[i] % j == 0){
                int v1 = j , v2 = x[i] / j;
                //if(i == 3){
                //    cout << "here" << v1 << " " << v2 << endl;
                //}
                if(v1 % 2 == 0 && v2 % 2 == 0){
                    if(v1 - v2 + 1 >= use + 1) 
                        can = min(can , mp(v1 - v2 + 1 , v1 + v2 - 1));
                    if(v2 - v1 + 1 >= use + 1)
                        can = min(can , mp(v2 - v1 + 1 , v2 + v1 - 1));
                }
                if(v1 % 2 == 1 && v2 % 2 == 1){
                    if(v1 - v2 + 1 >= use + 1)  
                        can = min(can , mp(v1 - v2 + 1 , v1 + v2 - 1));
                    if(v2 - v1 + 1 >= use + 1)
                        can = min(can , mp(v2 - v1 + 1 , v2 + v1 - 1));
                }
            }
        }
//       cout << "l = " << can.F << " " << "r = " << can.S << endl;
        if(can.F == INF) return cout << "No" << endl , 0;
        else {
            ans.pb(calc(use , can.F - 2));
            ans.pb(x[i]);
            use = can.S + 2;
        }
    }
    
    cout << "Yes" << endl;
    for(auto to : ans) cout << to << " " ; cout << endl;


    return 0;
}