#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,ans;
char a[5005][5005];
int line[10005];
int lt[10005],rt[10005];
int st[10005],top;

int del(int p)
{rt[lt[p]]=rt[p];lt[rt[p]]=lt[p];}

int add(int p)
{
    lt[p]=lt[n+1];
    rt[p]=n+1;
    rt[lt[p]]=p;
    lt[rt[p]]=p;
}


int main()
{
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1),lt[i]=i-1,rt[i]=i+1;
    rt[0]=1;lt[n+1]=n;
    for(int j=1;j<=m;j++)
    {
        top=0;
        for(int i=rt[0];i!=n+1;i=rt[i])
        {
            if(a[i][j]=='1')line[i]++;
            else line[i]=0,del(i),st[++top]=i;
        }
        for(int i=rt[0],k=0;i!=n+1;i=rt[i])
        {
            k++;
            ans=max(ans,k*line[i]);
        }
        while(top)add(st[top--]);
    }
    printf("%d\n",ans);
    return 0;
}