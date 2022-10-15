#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second


const int N=300000+5;
int n,k;
int v[N],t[N];

struct info
{
    int x;
    int id;
};

bool operator < (info a,info b)
{
    return a.x<b.x;
}

priority_queue<info>q;

int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=k;i++)
    {
        q.push({v[i],i});
    }
    ll cost=0;
    for(int i=k+1;!q.empty();i++)
    {
        if(i<=n)
            q.push({v[i],i});
        info foo=q.top();
        q.pop();
        int id=foo.id;
        ll cnt=i-id;
        ll add=v[id];
        cost+=cnt*add;
        t[id]=i;
    }
    cout<<cost<<"\n";
    for(int i=1;i<=n;i++)
        cout<<t[i]<<" ";
    cout<<"\n";
}