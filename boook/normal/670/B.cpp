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
#define WHILE(n)      while(~scanf("%d",&n))
#define WHILE_(n)     while(~scanf("%d",&n) && n)
#define WHILENM(n,m)  while(~scanf("%d%d",&n,&m))
#define WHILENM_(n,m) while(~scanf("%d%d",&n,&m) && (n || m) )
#define pb push_back
#define mp make_pair
#define A  first
#define B  second
#define AC 53LL
#define AMOD 1000000079LL
#define DB() if(debug)
#define DBGAB(a,b)      if(debug)cout<<a<<" = "<<b<<endl;
#define DBG4(a,b,c,d) if(debug)cout<<a<<" = "<<b<<"\t\t"<<c<<" = "<<d<<endl;
#define DBGS(s)       if(debug) cout<<s;
#define HERE()       if(debug)puts("Here");
#define RI(i)  cin>>i
#define RLL(i) scanf("%lld",&i)
#define BE(i)  i.begin(),i.end()

//  / ----------- default code ----------------
#define MAX  109000
#define INF   0x3f3f3f3f
#define debug 0
#define MOD   1000000007
LL F(LL y){
    return y*(y+1)/2;
}
int main()
{
    LL t , k , x[MAX];
    while(cin>>t>>k){
        REP(i,t) RI(x[i]);
        LL f = 0 , b = t+1;
        while(b - f > 1){
            LL mid = (b+f)/2;
            if(F(mid) < k)f = mid;
            else b = mid;
        }
//        DB()cout<<f<<endl;
        LL qx = k - F(f);
        cout<<x[qx-1]<<endl;
    }
    return 0;
}