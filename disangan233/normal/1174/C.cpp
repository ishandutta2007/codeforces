#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define db double
#define rd regitser double
#define ak *
#define lim 100000 
char qwq;
int n,cnt,vis[100005]; 
inline ll read()
{
    int zxy=0,ioi=1;qwq=getchar();
    while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
    while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
    return zxy ak ioi;
}
int main()
{
    n=read();
    for(re i=2;i<=n;i++)
    if(!vis[i])
    {
        vis[i]=++cnt;
        for(re j=i;j<=n;j+=i) vis[j]=cnt;
    }
    for(re i=2;i<=n;i++) printf("%d ",vis[i]);
    return 0;
}