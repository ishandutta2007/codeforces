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
#define DBGG(i,j)     cout << i << " " << j << "\n"
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << "\n"
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 2010
#define INF 0x3f3f3f3f

int n , q , ans = 0;
int a[MAX] , d[MAX] , b[MAX] , c[MAX];
VPII g;
int32_t main(){
    IOS;
    cin >> n;
    REPNM(i , 1 , n + 1) cin >> a[i] , d[a[i]] = i;
    REPNM(i , 1 , n + 1) cin >> c[i] , b[c[i]] = i;
    int ans = 0;
    REPNM(i , 1 , n + 1){
        int v = c[i] , xy = d[c[i]];
        RREP(j , xy - 1 , i){
            int tov = a[j] , toen = b[a[j]];
            if(toen >= xy){
                ans += xy - j;
                int tma = j , tmb = a[j];
                g.pb(mp(xy , j));
                swap(a[xy] , a[j]);
                swap(d[a[xy]] , d[a[j]]);
                xy = j;
                // cout << "--------" << "\n";
                // REPNM(l , 1 , n + 1) cout << a[l] << " " ; cout << "\n";
                // REPNM(l , 1 , n + 1) cout << d[l] << " " ; cout << "\n";
            }
        }
    }
    cout << ans << "\n";
    cout << g.size() << "\n";
    REP(i , g.size()) cout << g[i].A << " " << g[i].B << "\n";
    return 0;
}