#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n),c(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    for(int i=0;i<n;i++)
        cin >> c[i];

    vector<pii> vp;
    for(int i=0;i<n;i++)
        vp.push_back(pii(v[i],c[i]));

    sort(vp.begin(),vp.end());

    ll res=0,pos=0,sum=0,act=0;
    priority_queue<ll,vector<ll>,less<ll> > pq;
    while(pos<n || !pq.empty())
    {
        if(pq.empty())
            act=vp[pos].first;
        else
            act++;
        while(pos<n && vp[pos].first<=act)
        {
            sum+=vp[pos].second;
            pq.push(vp[pos].second);
            pos++;
        }

        if(!pq.empty())
        {
            sum-=pq.top();
            pq.pop();
        }
        res+=sum;
    }
    db(res)

    return 0;
}