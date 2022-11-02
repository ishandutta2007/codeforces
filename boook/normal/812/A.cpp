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
#define MAX 
#define INF 0x3f3f3f3f

int x[4][4];

int32_t main(){
    REP(i , 4) REP(j , 4) cin >> x[i][j];
    int ans = 0;
    REP(i , 4){
        if(x[i][3] == 0) continue;
        REP(j , 3) if(x[i][j]) ans = 1;
    }
    REP(i , 4){
        REP(j , 3){
            if(x[i][j] == 0) continue;
            int tmp ;
            if(j == 0) tmp = (i + 3) % 4;
            if(j == 1) tmp = (i + 2) % 4;
            if(j == 2) tmp = (i + 1) % 4;
            if(x[tmp][3]) ans = 1;
        }
    }

    if(ans) puts("YES");
    else puts("NO");
    return 0;
}