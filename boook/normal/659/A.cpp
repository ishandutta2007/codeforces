#include<bits/stdc++.h>
using namespace std;
#define REP(i,j) for(int i=0;i<j;i++)
#define REP(i,j,k) for(int i=j;i<k;i++)
#define MEM(i,j) memset(i,j,sizeof i)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n) while(scanf("%d%d",&n,&m)==2)
#define WHILENM_(n) while(scanf("%d%d",&n,&m)==2 && n && m)
#define mp(n,m) make_pair(n,m)
#define pb(n,m) push_back(n,m)
#define a first
#define b second
#define INF 0x3f3f3f3f
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int q = b+c;
        q = (q%a+a)%a;
        if(q==0)q=a;
        printf("%d\n",q);
    }

    return 0;
}