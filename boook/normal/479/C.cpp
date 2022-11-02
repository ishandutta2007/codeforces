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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , sum = 0 , use[MAX];
PII x[MAX];

int32_t main(){
    IOS;
    cin >> n;
    REP(i , n) cin >> x[i].A >> x[i].B;
    REP(times , n){
        
        PII tmp = mp(2000000000 , 2000000000);
        REP(j , n) if(use[j] != 1) tmp = min(tmp , x[j]);
        if(tmp.B < sum){
            sum = tmp.A;
            REP(j , n) if(use[j] != 1) {
                if(tmp == x[j]) { use[j] = 1 ; break; }
            }
        }
        else {
            sum = tmp.B;
            REP(j , n) if(use[j] != 1) {
                if(tmp == x[j]) { use[j] = 1 ; break; }
            }
        }
    }
    cout << sum << "\n";
    return 0;
}