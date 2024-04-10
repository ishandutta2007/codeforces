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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m;
int x[MAX][MAX] , a[MAX] , b[MAX] , ans[MAX][MAX] , xa[MAX] , xb[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , n) REP(j , m) cin >> x[i][j];
    REP(i , n) REP(j , m){
        if(x[i][j] == 0) a[i] = b[j] = 1;
    }
    int ok = 1;
    REP(i , n) REP(j , m) {
        if(a[i] || b[j]) ans[i][j] = 0;
        else ans[i][j] = 1 , xa[i] ++ , xb[j] ++;
    }
    REP(i , n) REP(j , m){
    	if(x[i][j] && xa[i] == 0 && xb[j] == 0) ok = 0;
    }
    if(!ok) cout << "NO\n" ;
    else {
        cout << "YES\n" ;
        REP(i , n){
            REP(j , m){
                if(a[i] || b[j]) cout << "0 ";
                else cout << "1 " ;
            }

            cout << "\n" ;
        }
    }
    return 0;
}