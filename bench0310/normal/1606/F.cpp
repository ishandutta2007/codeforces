#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void chmax(int &a,int b){a=max(a,b);}

const int N=200000;
const int S=450;

vector<int> v[N+1];
int sz[N+1];
int dp[N+1][S+1];
int tmp[S+1];

void small(int a,int p)
{
    for(int to:v[a])
    {
        if(to==p) continue;
        small(to,a);
        for(int k=0;k<=S;k++) dp[a][k]+=max(dp[to][k]-k,1);
    }
}

void big(int a,int p)
{
    sz[a]=1;
    for(int i=0;i<=S;i++) dp[a][i]=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        big(to,a);
        for(int i=0;i<=S;i++) tmp[i]=0;
        for(int i=0;i<=min(sz[a],S);i++)
        {
            chmax(tmp[i],dp[a][i]+1);
            for(int j=0;j<=sz[to]&&i+j+1<=S;j++)
            {
                chmax(tmp[i+j+1],dp[a][i]+dp[to][j]);
            }
        }
        sz[a]+=sz[to];
        for(int i=0;i<=min(sz[a],S);i++) dp[a][i]=tmp[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    small(1,0);
    int q;
    cin >> q;
    vector<int> a(q+1,0);
    vector<int> k(q+1,0);
    vector<int> res(q+1,0);
    for(int i=1;i<=q;i++)
    {
        cin >> a[i] >> k[i];
        if(k[i]<=S) res[i]=dp[a[i]][k[i]];
    }
    big(1,0);
    for(int i=1;i<=q;i++)
    {
        if(k[i]>S)
        {
            for(int j=0;j<=S;j++) chmax(res[i],dp[a[i]][j]-j*k[i]);
        }
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}