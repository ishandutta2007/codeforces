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
#define MAX 100
#define INF 0x3f3f3f3f

string s[MAX] , g;
int n;
int main(){
    cin >> n;
    REP(i , n) cin >> s[i];

    int nn = s[0].size();

    REP(i , n) s[i] += s[i];

    int ok = 1 , ans = INF;
    REPNM(i , 1 , n){
        int tok = 0;
        REP(j , nn){
            int qok = 1;
            REP(k , nn){
                if(s[0][k] != s[i][j + k]) qok = 0;
            }
            if(qok) tok = 1;
        }
        if(tok == 0) ok = 0;
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }

    REP(i , nn){
        int qq = 0;
        string goal = s[0].substr(i , nn);
        // cout << goal << endl;
        REP(j , n){
            REP(k , nn){
                if(s[j].substr(k , nn) == goal){
                    qq += k;
                    break;
                }
            }
        }
        ans = min(ans , qq);
    }
    cout << ans << endl;
    return 0;
}