#include<bits/stdc++.h>
using namespace std;
int ans[200];
void db()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=200;i++)
    {
        if(360%i!=0) continue;
        int ang=i;
        if(ang%2==0) ang/=2;
        for(int j=1;j*ang<=180-i;j++)
        {
            int cur=ang*j;
            if(!ans[cur]) ans[cur]=360/i;
            else ans[cur]=min(ans[cur],360/i);
        }
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("my.out","w",stdout);
    int T;
    db();
    scanf("%d",&T);
    while(T--)
    {
        int ang;
        scanf("%d",&ang);
        if(ans[ang]==0) puts("-1");
        else printf("%d\n",ans[ang]);
    }
}