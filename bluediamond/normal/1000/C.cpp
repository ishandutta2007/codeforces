#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=200000;

ll n;
struct info
{
    ll poz;
    ll tip;
    ///tip=1 => in
    ///tip=2 => out
};

bool operator<(info a,info b)
{
    return a.poz>b.poz;
}

priority_queue<info>q;

info v[N+5];
ll y=0;

void gt()
{
    y=0;
    info acm=q.top(); q.pop();
    v[++y]=acm;
    while(!q.empty())
    {
        info aux=q.top();
        if(aux.poz!=acm.poz)
            break;
        q.pop();
        v[++y]=aux;
    }
}

ll sum[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        ll st,dr;
        cin>>st>>dr;
        q.push({st,1});
        q.push({dr+1,2});
    }
    ll cur=0;
    ll ant=0;

    bool primul=1;

    while(!q.empty())
    {
        gt();
        if(primul==0)
        {
            ll len=v[y].poz-ant;
            sum[cur]+=len;
        }
        for(ll i=1;i<=y;i++)
        {
            if(v[i].tip==1)
                cur++;
            else
                cur--;
        }
        primul=0;
        ant=v[y].poz;
    }
    for(ll i=1;i<=n;i++)
        cout<<sum[i]<<" ";
    cout<<"\n";
    return 0;
}
/**

3 10
4 6 7


**/