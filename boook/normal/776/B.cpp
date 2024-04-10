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

int p[MAX];
void init(){
    REPNM(i , 2 , MAX){
        if(p[i]) continue;
        // cout << i << endl;
        for(LL j = (LL)i * (LL)i ; j < MAX ; j += i){
            p[j] = 1;
        }
    }
}
int main(){
    init();
    int n;
    while(~RI(n)){
        if(n <= 2){
            printf("1\n");
            if(n == 1) printf("1\n");
            else printf("1 1\n");
        }
        else {
        printf("2\n");
        printf("2");
        REPNM(i , 3 , n + 2){
            if(p[i])printf(" 1");
            else printf(" 2");
        }
        puts("");
            
        }
    }
    
    return 0;
}