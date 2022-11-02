#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long LL;
typedef pair<int , int> PII;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define MEM(i,j)      memset(i,j,sizeof i)
#define DB() if(debug)
#define DBGG(a,b)      if(debug)cout<<a<<" = "<<b<<endl;
#define DB4(a,b,c,d)   if(debug)cout<<a<<" = "<<b<<"\t\t"<<c<<" = "<<d<<endl;
#define HERE()          if(debug)puts("Here");
#define RI(i)        scanf("%d",&i)
#define RII(i,j)     scanf("%d%d",&i,&j)
#define RIII(i,j,k)  scanf("%d%d%d",&i,&j,&k)
#define RLL(i) scanf("%lld",&i)
#define ALL(i) i.begin(),i.end()
#define pb push_back
#define mp make_pair
#define A  first
#define B  second

//  / ----------- default code ----------------
#define MAX   109000
#define INF   0x3f3f3f3f
#define debug 0

int main()
{
    LL n , k , x[MAX];
    unordered_map<LL,LL> ma;
    while(~scanf("%I64d%I64d",&n,&k)){
        ma.clear();
        REP(i,n) RI(x[i]) , ma[x[i]]++;
        LL ans = 0;
        REP(i,n){
            LL q = x[i] ^ k;
            ma[x[i]]--;
            if(ma.count(q))ans+=ma[q];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}