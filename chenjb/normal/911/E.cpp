#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
int n,k;
int a[210000],stack[210000];
int v[210000];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)v[i]=0;
    for(int i=1;i<=k;i++){ scanf("%d",&a[i]); v[a[i]]=1; }
    int top=0;
    int now=0;
    for(int i=1;i<=k;i++)
    {
        if (top==0 || stack[top]>a[i])stack[++top]=a[i];
        else { puts("-1"); return 0; }
        while (top!=0 && stack[top]==now+1)now++,top--;
    }
    stack[top+1]=0;
    for(int i=top;i>0;i--)
    {
        for(int j=stack[i]-1;j>stack[i+1];j--)
            if (v[j]==0)a[++k]=j,v[j]=1;
    }
    for(int i=n;i>0;i--)
        if (v[i]==0)a[++k]=i;
    for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');
}