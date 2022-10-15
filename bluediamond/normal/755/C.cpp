#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N=10000+5;

int n,t[N],h[N];

inline int dad(int a)
{
    if(a==t[a])
        return a;
    t[a]=dad(t[a]);
    return t[a];
}

inline void unite(int a,int b)
{
    a=dad(a);
    b=dad(b);
    if(t[a]==t[b]) return;
    if(h[a]<h[b])
        t[a]=b;
    else
    {
        t[b]=a;
        h[b]+=(h[a]==h[b]);
    }
}

bool seen[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        t[i]=i, h[i]=1;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        unite(x,i);
    }

    int cnt=0;

    for(int i=1;i<=n;i++)
    {
        int x=dad(i);
        if(seen[x]==0) cnt++;
        seen[x]=1;
    }

    cout<<cnt<<"\n";

    return 0;
}
/**



**/