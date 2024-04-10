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

#define MAX 1000
#define INF 0x3f3f3f3f
//__gnu_pbds::priority_queue<PSI> pq;
typedef long long int LL;

int main()
{
    LL a[3];
    while(scanf("%I64d%I64d%I64d",&a[0],&a[1],&a[2])==3)
    {
        sort(a,a+3);
        LL ans=0;
        if(a[1] == a[2] && a[0]!=a[2])ans = a[2]-1-a[0];
        else if(a[1]!=a[2])ans = 2*(a[2]-1)-a[0]-a[1];
        else ans = 0;
        printf("%I64d\n",ans);
    }
    return 0;
}