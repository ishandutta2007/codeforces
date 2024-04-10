#include <bits/stdc++.h>

using namespace std;

const long long N=100000;
long long n,l;
long long aux[N+5],v[N+5];
long long iau[N+5];

bool ok(long long val)
{
    for(long long i=2;i<=n;i++)
        v[i]=aux[i];
    memset(iau,0,sizeof(iau));
    iau[1]=val;
    long long dr=0;
    for(long long st=1;st<=n;st++)
    {
        if(dr<=st)
            dr=st+1;
        bool bun=0;
        while(dr-st<=l)
        {
            if(v[dr]>=iau[st])
            {
                iau[dr]+=iau[st];
                v[dr]-=iau[st];
                bun=1;
                break;
            }
            iau[st]-=v[dr];
            iau[dr]+=v[dr];
            dr++;
        }
        if(bun==0)
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>l;
    for(long long i=2;i<=n;i++)
        cin>>aux[i];
    v[n+1]=(1LL<<60);
    long long r=0,pas=(1LL<<40);
    while(pas)
    {
        if(ok(r+pas)==1)
            r+=pas;
        pas/=2;
    }
    cout<<r;
    return 0;
}
/**

2 1
0



**/