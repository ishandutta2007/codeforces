#include <bits/stdc++.h>

using namespace std;

const long long N=1000+5;
const long long K=2000+5;

long long n,m,fi;
long long p[N];
long long k[K];

long long di(long long a,long long b)
{
    return abs(a-b);
}

bool ok(long long t)
{
    long long poz=1;
    for(long long i=1;i<=n;i++)
    {
        if(poz>m) return 0;
        while(1)
        {
            long long tot=di(p[i],k[poz])+di(k[poz],fi);
            if(tot<=t) break;
            poz++;
            if(poz>m) return 0;
        }
        poz++;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>fi;
    for(long long i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(long long i=1;i<=m;i++)
    {
        cin>>k[i];
    }
    sort(p+1,p+n+1);
    sort(k+1,k+m+1);
    long long r=-1,pas=(1LL<<60);
    while(pas)
    {
        if(ok(r+pas)==0)
        {
            r+=pas;
        }
        pas>>=1;
    }
    r++;
    cout<<r<<"\n";
    return 0;
}