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
#define MAX 150
#define INF 0x3f3f3f3f

void add(int x,int y,int d,int c[MAX][MAX])
{
    for(int i = x ; i <= MAX ; i += i & -i)
        for(int j = y ; j <= MAX ; j += j & -j)
            c[i][j] += d;
}
int get_sum(int x1,int y1,int c[MAX][MAX])
{
    int ans=0;
    for(int i = x1 ; i > 0 ; i-= i & -i)
        for(int j = y1 ; j > 0 ; j -= j & -j)
            ans += c[i][j];
    return ans;
}
int n , m;
string p[MAX];
int val[MAX][MAX] , bit[4][MAX][MAX];
void add_all(int x,int y,int addtag)
{
    if(!x || !y)return;
    add(1,1,addtag,bit[0]);
    add(x+1,1,-addtag,bit[0]);
    add(1,y+1,-addtag,bit[0]);
    add(x+1,y+1,addtag,bit[0]);
    add(x+1,y+1,x*y*addtag,bit[3]);
    add(x+1,1,x*addtag,bit[2]);
    add(x+1,y+1,-x*addtag,bit[2]);
    add(1,y+1,y*addtag,bit[1]);
    add(x+1,y+1,-y*addtag,bit[1]);
}
int get_sum_all(int x,int y)
{
    return get_sum(x,y,bit[0])*x*y + get_sum(x,y,bit[3]) + get_sum(x,y,bit[2])*y +get_sum(x,y,bit[1])*x;
}
int main(){
    cin >> n >> m;
    REP(i , n) cin >> p[i];
    REP(i , n) REP(j , m) val[i + 1][j + 1] = (p[i][j] == 'B') ? 1 : -1;

    int ans = 0;
    RREP(i , n , 1){
        RREP(j , m , 1){
            int tmp = get_sum_all(i , j) - get_sum_all(i , j - 1)
                 - get_sum_all(i - 1 , j) + get_sum_all(i - 1 , j - 1);
            int tq = val[i][j] - tmp; 
            if(tq) ans ++ , add_all(i , j , tq);
        }
    }
    cout << ans << endl;    
    return 0;
}