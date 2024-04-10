#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int n,L,k,s[1000],f[1000];
vector<int> p[200005];
int main()
{
    scanf("%d%d",&n,&k);L=sqrt(k*6);
    for(int i=1,x,y;i<=k;i++)
        scanf("%d%d",&x,&y),p[y+n-x].push_back(min(n-x,L));
    for(int i=1,t;i<=n;i++)
    {
        memset(s,0,L+2<<2);
        for(int j=0;j<p[i].size();j++)
            s[p[i][j]]++;
        for(int j=L;j>=0;j--)
            s[j]+=s[j+1];
        t=f[0]+s[0]*3;
        for(int j=min(i,L);j>0;j--)
        {
            t=min(t,f[j-1]+s[j]*3+j*(j+1)/2+2);
            f[j]=min(t,f[j-1]+s[j]*3);
        }
        f[0]=t;
    }
    printf("%d\n",f[0]);
    return 0;
}