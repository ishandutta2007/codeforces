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
typedef vector< PLL > VPLL;
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
#define MAX 400000
#define INF 0x3f3f3f3f

LL n , m , st;
VPLL v[MAX];
VLL ans;
LL eg[MAX] , use[MAX] , total;
void solve(){
    typedef pair<PLL , PLL> PLLL;
    __gnu_pbds::priority_queue<PLLL , greater<PLLL> > pq;
    pq.push(mp( mp(0 , eg[0]) , mp(st , 0)));
    while(pq.size()){
        PLLL now = pq.top(); pq.pop();
        if(use[now.B.A]) continue;
        use[now.B.A] = 1;
        ans.pb(now.B.B) , total += eg[now.B.B];
        for(auto i : v[now.B.A]){
            if(use[i.A]) continue;
            else pq.push(mp(mp(now.A.A + eg[i.B] , eg[i.B]) , mp(i.A , i.B)));
        }
    }
}
int main(){
    RLL(n , m);
    LL q , w , e;
    REP(i , m) RLLL(q , w , e) , v[q].pb(mp(w , i + 1)) , v[w].pb(mp(q , i + 1)) , eg[i + 1] = e;
    RL(st);
    solve();
    printf("%lld\n", total);
    REPNM(i , 1 , ans.size())
        printf("%lld ", ans[i]);
    puts("");
    return 0;
}