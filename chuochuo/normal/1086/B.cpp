#include<bits/stdc++.h>
using namespace std;
int deg[100005];
int n;double s;
int main()
{
    scanf("%d%lf",&n,&s);
    for(int i=0;i<n-1;i++)
    {
        int u,v;scanf("%d%d",&u,&v);deg[u]++;deg[v]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(deg[i]==1) cnt++;
    printf("%.10lf\n",s*2/cnt);
    return 0;
}