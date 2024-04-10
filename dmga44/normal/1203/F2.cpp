#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MAXN 60005

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,r,x,y;
    cin >> n >> r;
    vector<pii> a;
    vector<pip> b;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        if(y>=0)
            a.push_back(pii(x,y));
        else
            b.push_back(pip(x+y,pii(x,-y)));
    }

    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());

    int res=0;
    for(int i=0;i<a.size();i++)
        if(a[i].first<=r)
        {
            r+=a[i].second;
            res++;
        }
//    db(r)
//    db(res)
    for(int i=0;i<MAXN;i++)
        dp[i]=-200;
    dp[r]=res;
    for(int i=0;i<b.size();i++)
        for(int j=max(b[i].second.first,b[i].second.second);j<=r;j++)
            dp[j-b[i].second.second]=max(dp[j-b[i].second.second],dp[j]+1);

    for(int i=0;i<=r;i++)
        res=max(res,dp[i]);
    db(res)

    return 0;
}