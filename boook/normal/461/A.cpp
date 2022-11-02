#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
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
//#define RLL(i) scanf("%I64d",&i)
#define RLL(i) scanf("%I64d",&i)
#define ALL(i) i.begin(),i.end()
#define pb push_back
#define mp make_pair
#define A  first
#define B  second

//  / ----------- default code ----------------
#define MAX   100900
#define INF   0x3f3f3f3f
#define debug 1

int main(){
    LL t;
    while(~RLL(t)){
        LL q;
        priority_queue<LL> pq;
        LL ans = 0;
        REP(i,t) RLL(q) , pq.push(q) , ans += q;
        while(pq.size() > 1){
            LL q = pq.top(); pq.pop();
            LL w = pq.top(); pq.pop();
            ans += q+w;
            pq.push(q+w);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}