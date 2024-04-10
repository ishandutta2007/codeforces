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
#define MAX 400
#define INF 0x3f3f3f3f
#define debug 1
int p[MAX][MAX];
PII now;
int n , m , k , dir;
int NXT(){

    if((now.B == m && dir == 0) || (now.B == 1 && dir == 1)) now.A ++ , dir = 1 - dir; 
    else if(dir == 0) now.B ++;
    else now.B --;
    if(now.A == n + 1)return -1;
    return 0;    
}
int main(){
    while(~RIII(n , m , k)){
        dir = 0;
        int sum = n * m;
        MEM(p , 0);
        now = mp(1 , 1);
        REP(i , k - 1){
            printf("2") , sum -= 2;
            printf(" %d %d", now.A , now.B);
            NXT();
            printf(" %d %d", now.A , now.B);
            NXT();
            puts("");
        }
        printf("%d", sum);
        
        printf(" %d %d", now.A , now.B);
        for(;;){
            if(NXT() == -1)break;
            printf(" %d %d", now.A , now.B);
        }
        puts("");
    }
    return 0;
}