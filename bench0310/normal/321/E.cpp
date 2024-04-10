#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=4000;
vector<vector<int>> c(N,vector<int>(N,0));
vector<int> now(N,0);
vector<int> nxt(N,0);

void in(int &a)
{
    char x;
    while(!isdigit(x=getchar()));
    a=(x-'0');
    while(isdigit(x=getchar())) a=10*a+(x-'0');
}

void solve(int l,int r,int optl,int optr)
{
    if(l>r) return;
    int m=(l+r)/2;
    array<int,2> best={1<<30,-1};
    for(int i=optl;i<=min(m-1,optr);i++) best=min(best,{now[i]+c[i+1][m],i});
    nxt[m]=best[0];
    solve(l,m-1,optl,best[1]);
    solve(m+1,r,best[1],optr);
}

int main()
{
    int n,k;
    in(n);
    in(k);
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int o=0;o<n;o++) for(int i=0;i<n;i++) in(v[o][i]);
    vector<vector<int>> sum(n,vector<int>(n,0));
    for(int o=0;o<n;o++)
    {
        sum[o][0]=v[o][0];
        for(int i=1;i<n;i++) sum[o][i]=sum[o][i-1]+v[o][i];
    }
    for(int l=0;l<n;l++)
    {
        for(int r=l+1;r<n;r++)
        {
            c[l][r]=c[l][r-1]+sum[r][r-1];
            if(l>0) c[l][r]-=sum[r][l-1];
        }
    }
    for(int i=0;i<n;i++) now[i]=c[0][i];
    for(int i=0;i<k-1;i++)
    {
        solve(0,n-1,0,n-1);
        now=nxt;
    }
    printf("%d\n",now[n-1]);
    return 0;
}