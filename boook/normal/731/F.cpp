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
#define MAX 500900
#define INF 0x3f3f3f3f

int n , x[MAX] , cnt[MAX] , pre[MAX];

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) cnt[x[i]] ++;
    REP(i , 1 , MAX) pre[i] = pre[i - 1] + cnt[i];
    int ans = 0;
    REP(i , 1 , MAX){
        if(cnt[i] == 0) continue;
        int fr = i - 1 , nxt = i + i - 1 , val = i;
        int res = 0;
        while(nxt < MAX){
            res += (pre[nxt] - pre[fr]) * val;
            fr += i , nxt += i , val += i;
        }
        ans = max(ans , res);
    }
    cout << ans << endl;
    return 0;
}