#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int nmax=500;
int n,m,k;
char s[nmax+5];
int nr,P[nmax+5];
int best[nmax+5];
int aux[nmax+5],dp[nmax+5];
int main()
{
    scanf("%d%d%d\n",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        nr=0;
        gets(s);
        for(int j=0;j<m;j++)
            if(s[j]=='1')
                P[++nr]=j+1;
        for(int j=0;j<nr;j++)
            best[j]=1e9;
        best[nr]=0;
        for(int st=1;st<=nr;st++)
            for(int dr=st;dr<=nr;dr++)
            {
                int sterg=(st-1)+(nr-dr);
                best[sterg]=min(best[sterg],P[dr]-P[st]+1);
            }
        for(int j=0;j<=k;j++)
            aux[j]=2e9;
        for(int h=0;h<=nr;h++)
        {
            for(int j=0;j+h<=k;j++)
            {
                aux[j+h]=min(aux[j+h],dp[j]+best[h]);
            }
        }
        for(int j=0;j<=k;j++)
            dp[j]=aux[j];
    }
    cout<<dp[k];
    return 0;
}