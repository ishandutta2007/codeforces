#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> PII;
typedef long long int LL;
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
///---------------------------
#define MAX 20
#define INF 0x3f3f3f3f
#define debug 1

int main(){
    int n , m , k;
    RIII(n , m , k);
    int C = k%2;
    int row = m * 2;
    int A;
    if(k % row == 0)A = k/row;
    else A = k/row+1;
    int B;
    k -= (A-1)*row;
//    DBGG("k = ",k);
    if(k % 2) B = k/2 + 1;
    else B = k/2;

    printf("%d %d ",A , B);
    if(C)printf("L\n");
    else printf("R\n");
    return 0;
}