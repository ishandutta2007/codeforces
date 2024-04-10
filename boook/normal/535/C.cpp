#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define LL  long long int
#define PII pair<int , int>
#define PLL pair< LL , LL >
#define VI  vector<int> 
#define VLL vector<LL> 
#define VPII vector<PII>
#define VPLL vector<PLL>
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int a , b , n , q , w , e;
int F(int now){ return a + (now - 1) * b; }
int32_t main(){
    cin >> a >> b >> n;
    REP(times , n){
        cin >> q >> w >> e;
        if(w < F(q)) cout << -1 << endl;
        else {
            int now = q;
            RREP(i , 22LL , 0LL){
                int tmp = now + (1LL << i);
                if(F(tmp) > w) continue;
                if((a + a + (tmp + q - 2) * b) * (tmp - q + 1) <= w * e * 2) now = tmp;
            }
            cout << now << endl;
        }
    }
    return 0;
}