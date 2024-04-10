#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int a[5000000],b[5000000];
int nxt[10000000][2],tot[10000000];
int cnt;
int newnode()
{
    cnt++;
    nxt[cnt][0]=nxt[cnt][1]=0;
    tot[cnt]=0;
    return cnt;
}
void insert(int x, int v)
{
    int now=1;
    for(int i=29;i>=0;i--)
    {
        tot[now]+=v;
        int t;
        if ((x>>i) & 1)t=1; else t=0;
        if (nxt[now][t]==0)nxt[now][t]=newnode();
        now=nxt[now][t];
    }
    tot[now]+=v;
}

int get(int x)
{
    int ans=0;
    int now=1;
    for(int i=29;i>=0;i--)
    {
        int t;
        if ((x>>i) & 1)t=1; else t=0;
        if (tot[nxt[now][t]])
        {
            ans=ans|(t<<i);
            now = nxt[now][t];
        }
        else
        {
            ans=ans|((t^1)<<i);
            now=nxt[now][t^1];
        }
    }
    return ans;
}

int main()
{    
    int n;
    cnt=-1;
    newnode();
    newnode();
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)insert(b[i],1);
    for(int i=1;i<=n;i++)
    {
        int t = get(a[i]);
        a[i]^=t;
        insert(t,-1);
        printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}