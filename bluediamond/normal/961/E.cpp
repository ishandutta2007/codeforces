#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000+5;

int n;
int v[N];

vector<int>out[N];
int aib[N];

inline void add(int p,int x)
{
    for(int i=p;i<=n;i+=i&(-i))
    {
        aib[i]+=x;
    }
}

inline int prefix(int p)
{
    int a=0;
    for(int i=p;i>=1;i-=i&(-i))
    {
        a+=aib[i];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]+1<=n)
        {
            out[v[i]+1].push_back(i);
        }
        add(i,1);
    }
    ll a=0LL;
    for(int i=1;i<=n;i++)
    {
        int p=min(i-1,v[i]);
        for(auto &it:out[i])
        {
            add(it,-1);
        }
        a+=prefix(p);
    }
    cout<<a<<"\n";
    return 0;
}
/**


**/