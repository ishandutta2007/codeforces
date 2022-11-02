#include <bits/stdc++.h>
using namespace std;
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
#define MAX 1000000010
#define INF 0x3f3f3f3f

VI x;
int32_t main(){
    x.pb(4) , x.pb(7);
    REP(i , x.size()){
        if(x[i] > MAX) continue;
        x.pb(x[i] * 10 + 4);
        x.pb(x[i] * 10 + 7);
    }
    sort(ALL(x));
    int n;
    cin >> n;
    int ans = lower_bound(ALL(x) , n) - x.begin();
    cout << ans + 1 << endl;
    return 0;
}