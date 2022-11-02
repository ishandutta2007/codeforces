/*input
4
0 5 15 10
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f

int n, x[MAX] , y[MAX];

int32_t main(){
    IOS;
    // REP(i , 1 , MAX) for(int j = 0; j < MAX ; j += i) x[j] ++;
    // REP(i , 1 , MAX) if(x[i] > 200) cout << i << " "; cout << endl;
    // 554400 655200 665280 720720 776160 786240 831600 856800 887040 900900 
    // 907200 917280 942480 957600 960960 970200 982800 997920 
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];

    int ans = (1ll << 60) , total = 0;
    REP(i , 1 , n + 1) total += x[i];

    if(total == 1) return cout << -1 << endl , 0;

    vector<int> QQ;
    REP(i , 2 , total + 1){
        if(i * i > total) break;
        else if(total % i == 0){
            QQ.pb(i);
            while(total % i == 0) total /= i;
        }
    }if(total != 1) QQ.pb(total);

    for(auto inv : QQ){

        REP(i , 1 , n + 1) y[i] = x[i];

        // DBGG("i = " , inv);
        int mid = (inv + 1) / 2 , sum = 0, hand = 0 , tomid;

        int now = 1;
        while(now <= n){
            if(sum > ans) break;
            if(hand == 0) y[now] %= inv;
            // DB4("now = " , now , "y[now] = " , y[now]);
            if(y[now] == 0){
                if(hand < mid) sum += hand;
                now ++;
            }
            else if(hand < mid){
                int take = min(mid - hand , y[now]);
                y[now] -= take;
                hand += take;
                if(hand == mid) tomid = now;
            }
            else if(hand >= mid) {
                int take = min(inv - hand , y[now]);
                y[now] -= take;
                sum += take * (now - tomid);
                hand += take;
                if(hand == inv) hand = 0;
            }
            // cout << "sum = " << sum << " ";
            // DB4("now = ", now, "hand = " , hand);
        }
        // DB4("inv = " , inv , "ans = " , sum);
        ans = min(ans , sum);
    }
    cout << ans << endl;
    return 0;
}