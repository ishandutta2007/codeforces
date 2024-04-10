#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
const int Mod=998244353;
int fp(int a,int k)
{
    if(k<0)a=fp(a,Mod-2),k=-k;
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}

int C[MAXN][MAXN],Inv[MAXN<<1];
int D[MAXN][MAXN<<1],E[MAXN];
int main()
{
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    for(int i=(C[0][0]=1);i<=n;i++)
        for(int j=(C[i][0]=1);j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    D[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=2*i;j++)
        {
            D[i+1][j+2]=(D[i+1][j+2]-2LL*D[i][j]%Mod+Mod)%Mod;
            D[i+1][j+1]=(D[i+1][j+1]+2LL*D[i][j])%Mod;
        }
    for(int i=1;i<=2*n+1;i++)
        Inv[i]=fp(i,-1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=2*i;j++)
            E[i]=(E[i]+1LL*D[i][j]*Inv[j+1])%Mod;
    int res=0;
    for(int t=k;t<=n;t++)
    {
        int tmp=0;
        for(int i=0;i<=n-t;i++)
        {
            int mul=1LL*C[n-t][i]*E[i+t]%Mod;
            if(~i&1)tmp=(tmp+mul)%Mod;
            else tmp=(tmp-mul+Mod)%Mod;
        }
        res=(res+1LL*C[n][t]*tmp)%Mod;
    }
    res=1LL*res*l%Mod;
    printf("%d\n",res);
    return 0;
}