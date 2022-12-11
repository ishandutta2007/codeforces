#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
priority_queue <int> q;
int n,m,tp,ans,sum;

inline int read()
{
    int n=0,f=1; char c=getchar();
    while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
    while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
    return n*f;
}

int main()
{
    register int i,x;
    n=read(); m=read();
    tp=m-1;
    for (i=1;i<=min(n,m-1);++i)
    {
        --tp;
        while (!q.empty()&&q.top()>tp) q.pop(),--ans;
        x=read()-i;
        if (x+i<m&&x<=tp) q.push(x),++ans;
        sum=max(ans,sum);
    }
    printf("%d",sum);
}