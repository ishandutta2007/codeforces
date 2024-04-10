#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MN 1000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int mark[MN+5],n,a[105],res[105];
int main()
{
    for(int t=read();t;--t)
    {
        n=read();
        for(int i=1;i<=n;++i) a[i]=read();
        sort(a+1,a+n+1);int num=0;
        for(int i=1;i<=MN&&num<n;++i)
            if(mark[i]!=t)
            {
                res[++num]=i;
                for(int j=2;j<=n;++j)
                    for(int k=1;k<n;++k)
                        if(i+a[j]-a[k]<=MN&&i+a[j]-a[k]>0)
                            mark[i+a[j]-a[k]]=t;
            }
        if(num==n)
        {
            puts("YES");
            for(int i=1;i<=n;++i) printf("%d%c",res[i],i==n?'\n':' ');
        }
        else puts("NO");
    }
    return 0;
}