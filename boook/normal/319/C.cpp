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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , dp[MAX];

int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];

    dp[1] = b[1];
    deque<int> dq;
    dq.push_back(1);
    REP(i , 2 , n + 1){
        while(dq.size() >= 2){
            int v1 = dp[dq[0]] + (a[i] - 1) * b[dq[0]] + b[i];
            int v2 = dp[dq[1]] + (a[i] - 1) * b[dq[1]] + b[i];
            if(v1 > v2) dq.pop_front();
            else break;
        }
        dp[i] = dp[dq[0]] + (a[i] - 1) * b[dq[0]] + b[i];
        while(dq.size() >= 2){
            int pre = dq[dq.size() - 2] , mid = dq[dq.size() - 1] , now = i;

            double t1 = (double)(dp[mid] - (double)dp[pre]) * ((double)b[mid] - (double)b[now]);
            double t2 = (double)(dp[now] - (double)dp[mid]) * ((double)b[pre] - (double)b[mid]);
            if(t2 < t1) dq.pop_back();
            else break;
        }
        dq.push_back(i);
        // DB4("dp[" , i , "] = " , dp[i]);
        // for(auto to : dq) cout << to << " " ; cout << endl;
    }

    cout << dp[n] << endl;
    return 0;
}