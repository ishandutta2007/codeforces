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
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
typedef long long int LL;
#define MAX 100000
#define INF 0x3f3f3f3f

int p[MAX] , dv[MAX] , po = 0;
void pre(){
    REPNM(i , 2 , MAX){
        if(p[i] == 0){
            // cout << i << " " ; 
            dv[po++] = i;
            for(LL j = LL(i) * LL(i) ; j < MAX ; p[j] = 1 , j += i);
        }
    }
    // cout << endl;
}
int W(int now){
    if(now < MAX) return !p[now];
    REP(i , po){
        LL tmc = dv[i];
        if(tmc * tmc > now) break;
        if(now % tmc == 0) return 0;
    }
    return 1;
}
int F(int now){
    RREP(i , now , 0){
        if(W(i)) return i;
    }
}
PII G(int now){
    REP(i , po){
        if(W(now - dv[i])) return mp(dv[i] , now - dv[i]);
    }
    REPNM(i , MAX , INF){
        if(W(i) && W(now - i)) return mp(dv[i] , now - dv[i]);
    }
}
int32_t main(){
    pre();
    int n;
    cin >> n;
    if(W(n)){
        cout << 1 << endl;
        cout << n << endl;
    }
    else {
        int tmp = F(n - 4);
        PII ans = G(n - tmp);
        cout << 3 << endl;
        cout << tmp << " " << ans.A << " " << ans.B << endl;
    }
    return 0;
}