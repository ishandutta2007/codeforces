#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

pii op[MAXN];
ll dp[205][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m,k,s,t,d,w;
    cin >> n >> m >> k;
    for(int i=1;i<MAXN;i++)
        op[i]=pii(-1,-1);
    vector<ppp> v;
    for(int i=0;i<k;i++)
    {
        cin >> s >> t >> d >> w;
        v.push_back(ppp(pii(s,t),pii(w,d)));
    }

    sort(v.begin(),v.end());

    priority_queue<pip,vector<pip>,less<pip> > pq;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        while(p<k && v[p].first.first<=i)
        {
            pq.push(pip(v[p].second.first,pii(v[p].second.second,v[p].first.second)));
            p++;
        }

        while(!pq.empty() && pq.top().second.second<i)
            pq.pop();

        if(!pq.empty())
            op[i]=pii(pq.top().first,pq.top().second.first);
    }

    for(int i=n;i>=1;i--)
    {
        if(op[i]!=pii(-1,-1))
        {
            dp[0][i]=op[i].first;
            dp[0][i]+=dp[0][op[i].second+1];
        }
        else
            dp[0][i]=dp[0][i+1];
    }

    for(int i=1;i<=m;i++)
        for(int j=n;j>=1;j--)
        {
            if(op[j]!=pii(-1,-1))
            {
                ll mi=op[j].first+dp[i][op[j].second+1];
                mi=min(mi,dp[i-1][j+1]);
                dp[i][j]=mi;
            }
            else
                dp[i][j]=min(dp[i][j+1],dp[i-1][j+1]);
        }

    db(dp[m][1])

    return 0;
}