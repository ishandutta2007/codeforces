#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 2005

ll a[MAXN],b[MAXN],ma[MAXN*MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m,x;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    cin >> x;

    vector<pii> nn,mm;
    for(int i=0;i<n;i++)
    {
        ll sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            nn.push_back(pii(sum,j-i+1));
        }
    }

    for(int i=0;i<m;i++)
    {
        ll sum=0;
        for(int j=i;j<m;j++)
        {
            sum+=b[j];
            mm.push_back(pii(sum,j-i+1));
        }
    }

    sort(nn.begin(),nn.end());
    sort(mm.begin(),mm.end());

    ll r=mm.size()-1;
    ma[0]=mm[0].second;
    for(int i=1;i<mm.size();i++)
        ma[i]=max(ma[i-1],mm[i].second);

    ll res=0;
    for(int i=0;i<nn.size();i++)
    {
        while(r>=0 && (nn[i].first*mm[r].first)>x)
            r--;
        if(r>=0)
            res=max(res,nn[i].second*ma[r]);
    }
    db(res)

    return 0;
}