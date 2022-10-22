#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 2005
#define oo 1e9

vector<pii> v;
int dp[MAXN];
int mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int a,n,m,l,r;
    cin >> a >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> l >> r;
        for(int j=l+1;j<=a;j++)
            dp[j]=oo;
        for(int j=l;j<=r;j++)
            mk[j]=i+1;
    }

    for(int i=0;i<m;i++)
    {
        cin >> l >> r;
        v.push_back(pii(l,r));
    }

    sort(v.begin(),v.end());

    for(int i=0;i<m;i++)
    {
        int x=v[i].first;
        int y=v[i].second;
        int c=0;
        int p=dp[x];
        for(int j=x+1;j<=a;j++)
        {
            if(mk[j]==mk[j-1] && mk[j])
                c=(j-x)*y;
            dp[j]=min(dp[j],c+p);
        }
    }

    if(dp[a]==oo)
        dp[a]=-1;
    db(dp[a])

    return 0;
}