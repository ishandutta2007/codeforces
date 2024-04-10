#include<bits/stdc++.h>
#define x first
#define y second
#define y1 BbI4a
///#define int long long
///#define mp make_pair
using namespace std;

int dp[5021][5021];
int bor[12500000][3];
string s,ans;
int n,k,sz,cur;
int d[12500000],cnt[12500000];

inline int move_l(int x)
{
    if(bor[x][1]==0)
    {
        ++sz;
        bor[x][1]=sz;
    }
    return bor[x][1];
}

inline int move_r(int x)
{
    if(bor[x][2]==0)
    {
        ++sz;
        bor[x][2]=sz;
    }
    return bor[x][2];
}

void dfs(int x)
{
    d[x]=cnt[x];
    for(int i=1;i<=2;++i)
        if(bor[x][i]!=0)
        {
            dfs(bor[x][i]);
            d[x]+=d[bor[x][i]];
        }
}

void go(int x,int y)
{
    y-=cnt[x];
    if(y<=0)
    {
        return;
    }else
    if(bor[x][1]==0)
    {
        cout<<'b';
        go(bor[x][2],y);
    }else
    if(bor[x][2]==0)
    {
        cout<<'a';
        go(bor[x][1],y);
    }else
    if(d[bor[x][1]]>=y)
    {
        cout<<'a';
        go(bor[x][1],y);
    }else
    {
        cout<<'b';
        go(bor[x][2],y-d[bor[x][1]]);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    cin>>k;
    n=s.size();
    s="!"+s;
    for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)dp[i][j]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n;++i)
        {

            int j=i+len-1;
            if(j>n)break;
            if(s[i]!=s[j])continue;
            if(len<6)dp[i][j]=1;else dp[i][j]=dp[i+2][j-2];
        }
    }
    sz=1;
    for(int i=1;i<=n;++i)
    {
        int cur=1;
        for(int j=i;j<=n;++j)
        {
            if(s[j]=='a')
                cur=move_l(cur);
            else
                cur=move_r(cur);
            if(dp[i][j]==1)cnt[cur]++;
        }
    }
    dfs(1);
    go(1,k);
}