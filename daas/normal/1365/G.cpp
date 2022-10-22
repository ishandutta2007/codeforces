#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
#define int long long
#define lowbit(k) (k&-k)
using namespace std;
int read()
{
    int kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-') c=getchar();
    if(c=='-') c=getchar(),x=-1;
    while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
    return kkk*x;
}
int n,id[1010],num[1010],val[20];
int check(int s)
{
    int cnt=0;
    while(s) ++cnt,s-=lowbit(s);
    if(cnt==6) return 1;
    return 0;
}
signed main()
{
    n=read();
    for(int s=0;s<(1<<13) && id[0]<n;++s)
        if(check(s)) id[++id[0]]=s;
    for(int i=0;i<13;++i)
    {
        num[0]=0;
        for(int j=1;j<=n;++j) if((id[j]>>i)&1ll) num[++num[0]]=j;
        if(num[0])
        {
            printf("? %lld",num[0]);
            for(int j=1;j<=num[0];++j) printf(" %lld",num[j]);
            putchar('\n');
            fflush(stdout);
            val[i]=read();
        }
    }
    putchar('!');
    for(int i=1;i<=n;++i)
    {
        int ans=0;
        for(int j=0;j<13;++j) if(((id[i]>>j)&1ll)==0) ans|=val[j];
        printf(" %lld",ans);
    }
    putchar('\n');
    return 0;
}