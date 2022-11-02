#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
typedef long long LL;
#define MAP 500000
#define MAX 5050
#define INF 0x3f3f3f3f

set<int> bad;
int p[MAP] , po = 0 , dv[MAP];
void pre(){
    REPNM(i , 2 , MAP){
        if(dv[i] == 0) p[po ++] = i , dv[i] = i;
        REP(j , po){
            LL tmp = p[j];
            if(tmp * i >= MAP) break;
            dv[tmp * i] = tmp;
            if(i % tmp == 0) break;
        }
    }
}

int n , m , x[MAX] , dp[MAX] , g[MAX];

int P(int now){
    if(now < MAP) return dv[now];
    REP(i , po){
        LL tmp = p[i];
        if(tmp * tmp > now) return now;
        if(now % tmp == 0) return tmp;
    }
    return now;
}
int F(int now){
    int val = 0;
    while(now != 1){
        int tmp = P(now);
        if(bad.find(tmp) != bad.end()) val --;
        else val ++;
        now /= tmp;
    }
    return val;
}


int32_t main(){
    IOS;
    pre();
    cin >> n >> m;
    REP(i , n) cin >> x[i];
    int tmc;
    REP(i , m) cin >> tmc , bad.insert(tmc);
    int ans = 0;

    g[0] = x[0];
    REPNM(i , 1 , n) g[i] = __gcd(g[i - 1] , x[i]);

    RREP(i , n - 1 , 0){
        dp[i] = -F(g[i]) * (i + 1);
        REPNM(j , i + 1 , n){
            int tmp = g[i] / g[j];
            dp[i] = max(dp[i] , dp[j] + (-F(tmp) * (i + 1)));
        }
        ans = max(ans , dp[i]);
        // DB4("dp[" , i , "] = " , dp[i]);
    }
    // DBGG("ans = " , ans);
    REP(i , n) ans += F(x[i]);
    cout << ans << "\n";
    return 0;
}