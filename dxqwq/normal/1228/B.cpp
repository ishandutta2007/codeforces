#include<bits/stdc++.h>
#define ll long long
using namespace std;
int h,w,mp[1005][1005];
ll cnt=0;
const ll MOD=1000000000+7;
ll ksm(ll basic,ll mi)
{
    ll tmp=1;
    while(mi)
    {
        if(mi&1)tmp=tmp*basic%MOD;
        mi>>=1;
        basic=basic*basic%MOD;
    }
    return tmp;
}
int main()
{
    memset(mp,-1,sizeof(mp));
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;++i)
    {
        int kk;
        scanf("%d",&kk);
        for(int j=1;j<=kk;++j)mp[i][j]=1;
        mp[i][kk+1]=0;//r[i]
    }
    for(int i=1;i<=w;++i)
    {
        int kk;
        scanf("%d",&kk);
        for(int j=1;j<=kk;++j)
        {
            if(mp[j][i]==0)
            {
                printf("0\n");
                return 0;
            }
            mp[j][i]=1;
        }
        if(mp[kk+1][i]==1)
        {
            printf("0\n");
            return 0;
        }
        mp[kk+1][i]=0;//c[
    }
    for(int i=1;i<=h;++i)
    {
        for(int j=1;j<=w;++j)
        {
            if(mp[i][j]==-1)++cnt;//
        }
    }
    printf("%d\n",ksm(2,cnt));
    return 0;
}