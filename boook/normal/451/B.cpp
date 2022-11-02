#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout<<i<<" "<<j<<endl;
#define DB4(i,j,k,l)  if(debug) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
#define RI(i)       scanf("%d",&i)
#define RII(i,j)    scanf("%d%d",&i,&j)
#define RIII(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define RL(i)       scanf("%lld",&i)
#define RLL(i,j)    scanf("%lld%lld",&i,&j)
#define RLLL(i,j,k) scanf("%lld%lld%lld",&i,&j,&k)
#define AS assert
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f
#define debug 1
int x[MAX];
int main(){
    int n;
    while(~RI(n)){
        REP(i , n) RI(x[i]);
        int sum = 0 , L , R;
        REP(i , n - 1){
            if(sum > 1) break;
            if(x[i] > x[i + 1]){
                sum ++;
                L = i;
                R = i + 1;
                while(R + 1 < n && x[R] >= x[R + 1]) R ++;
                i = R + 1;
            }
        }
        if(sum == 0) puts("yes\n1 1");
        else if(sum != 1) puts("no");
        else {
            int Q = L , W = R;
            while(R > L) swap(x[L++] , x[R--]);
            int tok = 1;
            REP(i , n - 1){
                if(x[i] > x[i + 1]) tok = 0;
            }
            if(!tok) puts("no");
            else printf("yes\n%d %d\n" ,  Q + 1 , W + 1);
        }
    }
    return 0;
}