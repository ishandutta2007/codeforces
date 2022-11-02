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
#define MAX 2000
#define INF 0x3f3f3f3f

int a , b , c , d , e;
int x[MAX];
int32_t main(){
    cin >> a >> b >> c >> d >> e;
    int sum = 0 , cntq = 0 , cntw = 0;
    REP(i , b) cin >> x[i] , sum += x[i];
    REP(i , b)
        if(x[i] >= e) cntq ++;
        else cntw ++;

    int tmp = sum , wa = a / 2;
    VI ans;
    if(cntw > wa){
        cout << -1 << endl;
        return 0;
    }
    else if(cntq > wa + 1){
        REP(i , a - b) ans.pb(1) , tmp ++;
        if(tmp > d) {
            cout << -1 << endl;
            return 0;
        }
        else for(auto i : ans) cout << i << " " ; cout << endl;
    }
    else {
        REP(i , wa - cntw) ans.pb(1) , tmp ++;
        REP(i , wa + 1 - cntq) ans.pb(e) , tmp += e;
        if(tmp > d) {
            cout << -1 << endl;
            return 0;
        }
        else for(auto i : ans) cout << i << " " ; cout << endl;
    }
    return 0;
}