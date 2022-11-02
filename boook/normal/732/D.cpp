#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
typedef pair<int,int> PII;
#define REP(x,y) for(int x=0;x<y;x++)
#define REPNM(x,y,z) for(int x=y;x<z;x++)
#define MEM(x,y) memset(x,y,sizeof x)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n,m) while(scanf("%d%d",&n,&m)==2)
#define mp(n,m) make_pair(n,m)
#define AC 37
#define BC 41
#define AMOD 100000017
#define BMOD 100000029
#define a first
#define b second

#define MAX 100010
#define INF 0x3f3f3f3f
//__gnu_pbds::priority_queue<PSI> pq;
typedef long long int LL;


int n , m , x[MAX] , w[MAX] , day[MAX];
bool Can(int y)
{
    REP(i,y) day[x[i]]=i;
    priority_queue<PII,vector<PII> , greater<PII> > pq;
    REPNM(i,1,m+1)
    {
        if(day[i]==-1)return 0;
        else pq.push(mp(day[i],i));
    }
    int noans=0 , uu=0 , ans;
    while(pq.size())
    {
        PII now =  pq.top(); pq.pop();
//        cout<<now.a<<"  "<<now.b<<"   "<<w[now.b]<<endl;
        if(now.a - uu >= w[now.b])
        {
            uu+=w[now.b]+1;
//            printf("UU=%d\n",uu);
            ans=max(ans,now.a);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{

    WHILENM(n,m)
    {

        REP(i,n) scanf("%d",&x[i]);
        REPNM(i,1,m+1) scanf("%d",&w[i]);
//        cout<<Can(5)<<endl;
        int f=-1,b=n+1,ans=n+1;
        while(b-f>1)
        {
            MEM(day,-1);
            int m=(b+f)/2;
            if(Can(m))b=m,ans=m;
            else f=m;
        }
        if(ans==n+1)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}