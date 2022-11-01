#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> solve(vector<array<int,2>> zero,vector<array<int,2>> one)
{
    vector<int> d(n+2,0);
    for(auto [l,r]:one)
    {
        d[l]++;
        d[r+1]--;
    }
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++) v[i]=v[i-1]+d[i];
    vector<int> nxt(n+2,n+1);
    for(int i=n;i>=1;i--)
    {
        if(v[i]==0) nxt[i]=i;
        else nxt[i]=nxt[i+1];
    }
    for(auto [l,r]:zero)
    {
        if(nxt[l]>r)
        {
            printf("NO\n");
            exit(0);
        }
    }
    for(int i=1;i<=n;i++) v[i]=min(v[i],1);
    return v;
}

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    vector<array<int,2>> zero[30];
    vector<array<int,2>> one[30];
    for(int i=0;i<m;i++)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        for(int j=0;j<30;j++)
        {
            if((x)&(1<<j)) one[j].push_back({l,r});
            else zero[j].push_back({l,r});
        }
    }
    vector<int> res(n+1,0);
    for(int i=0;i<30;i++)
    {
        vector<int> v=solve(zero[i],one[i]);
        for(int j=1;j<=n;j++) if(v[j]==1) res[j]+=(1<<i);
    }
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}