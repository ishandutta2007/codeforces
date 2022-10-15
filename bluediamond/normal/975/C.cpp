#include <bits/stdc++.h>

using namespace std;

const long long N=200000;
long long n,q;
long long v[N+5],sum[N+5];
long long poz,h_cur;

void afis()
{
    cout<<n+1-poz<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    poz=1;
    h_cur=v[1];
    for(long long i=1;i<=q;i++)
    {
        long long foo;
        cin>>foo;
        if(foo<=h_cur)
        {
            h_cur-=foo;
            if(h_cur==0)
            {
                poz++;
                if(poz>n)
                    poz=1;
                h_cur=v[poz];
            }
            afis();
            continue;
        }
        foo-=h_cur;
        poz++;
        if(foo>=sum[n]-sum[poz-1])
        {
            poz=1;
            h_cur=v[1];
            afis();
            continue;
        }
        long long r=poz-1,pas=(1<<17);
        while(pas)
        {
            if(r+pas<=n && sum[r+pas]-sum[poz-1]<=foo)
                r+=pas;
            pas/=2;
        }
        foo-=(sum[r]-sum[poz-1]);
        poz=r;
        poz++;
        h_cur=v[poz]-foo;
        afis();
    }
    return 0;
}