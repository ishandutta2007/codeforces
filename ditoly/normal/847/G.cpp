#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 1000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char st[MN+5][20];
int n,mx=0;
int main()
{
    n=read();
    for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
    for(int i=1;i<=7;++i)
    {
        int x=0;
        for(int j=1;j<=n;++j) x+=st[j][i]=='1';
        mx=max(mx,x);
    }
    cout<<mx;
    return 0;
}