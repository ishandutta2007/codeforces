#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< LL > VLL;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , x[MAX];

int32_t main(){
    cin >> n;
    REP(i , n) cin >> x[i];
    int q = x[0];
    REPNM(i , 1 , n) q = __gcd(q , x[i]);
    cout << "YES" << endl;
    if(q != 1) cout << 0 << endl;
    else {
        int ans = 0;
        RREP(i , n - 1 , 0){
            while(x[i + 1] % 2 != 0){
                int a = x[i] , b = x[i + 1];
                x[i] = a - b , x[i + 1] = a + b;
                ans ++;
            }
        }
        while(x[0] % 2 != 0){
            int a = x[0] , b = x[1];
            x[0] = a - b , x[1] = a + b;
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}