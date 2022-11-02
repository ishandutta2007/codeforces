#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef unsigned long long LL;
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
#define RLLLL(i,j) scanf("%I64d%I64d",&i,&j)
#define ALL(i) i.begin(),i.end()
#define pb push_back
#define mp make_pair
#define A  first
#define B  second

/// ----------- default code ----------------
#define MAX   300
#define INF   0x3f3f3f3f
#define debug 1

int main()
{
    LL n;
    while(~RLL(n)){

        LL a = n;
        LL b = n+1;
        LL c = a*b;
        if(c > 1000000000 || n == 1)puts("-1");
        else cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}