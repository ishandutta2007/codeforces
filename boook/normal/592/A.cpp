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
#define MAX 1000
#define INF 0x3f3f3f3f

string p[MAX];
int F(int a , int b){
    REPNM(i , a + 1 , 8) if(p[i][b] != '.') return INF;
    return 7 - a;
}
int G(int a , int b){
    RREP(i , a - 1 , 0) if(p[i][b] != '.') return INF;
    return a;
}
int32_t main(){

    REP(i , 8) cin >> p[i];
    int a = INF , b = INF;
    REP(i , 8){
        REP(j , 8){
            if(p[i][j] == 'B') b = min(b , F(i , j));
            if(p[i][j] == 'W') a = min(a , G(i , j));
        }
    }
    // DBGG(a , b);
    if(a <= b) cout << "A\n";
    else cout << "B\n";

    return 0;
}