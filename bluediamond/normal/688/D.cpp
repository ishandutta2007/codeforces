#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000000+5;

int n,k;

vector<int>p,e,sl;


void build()
{
    for(int d=2;d*d<=k;d++)
    {
        int cnt=0;
        while(k%d==0)
        {
            k/=d;
            cnt++;
        }
        if(cnt)
        {
            p.push_back(d);
            e.push_back(cnt);
            sl.push_back(0);
        }
    }
    if(k>1)
    {
        p.push_back(k);
        e.push_back(1);
        sl.push_back(0);
    }
}

int mul(int a,int b)
{
    return a*b;
}

int expow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}

bool seen[N];

bool ok(int x)
{
    if(x==1)
    {
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        seen[x]=1;
    }
    build();
    for(int it=0;it<p.size();it++)
    {
        int x=expow(p[it],e[it]);
    ///    cout<<p[it]<<" , "<<e[it]<<" : "<<x<<"\n";
        bool ok=0;
        for(int j=x;j<N;j+=x)
        {
            if(seen[j])
            {
                ok=1;
                break;
            }
        }
        if(ok==0)
        {
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}
/**

2 9
3 3

**/