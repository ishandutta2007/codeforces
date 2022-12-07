#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int p[n], pr=-1, an=0, yk=0;
    char co[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &p[a]);
        cin>>co[a];
    }
    while(yk<n)
    {
        int lr=inf, rr=-inf, lb=inf, rb=-inf;
        while(yk<n)
        {
            if(co[yk]=='G') break;
            if(co[yk]=='R')
            {
                lr=min(lr, p[yk]), rr=max(rr, p[yk]);
            }
            if(co[yk]=='B')
            {
                lb=min(lb, p[yk]), rb=max(rb, p[yk]);
            }
            yk++;
        }
        if(!(pr==-1 and yk==n))
        {
            if(pr==-1)
            {
                if(lr!=inf) an+=p[yk]-lr;
                if(lb!=inf) an+=p[yk]-lb;
            }
            else if(yk==n)
            {
                if(lr!=inf) an+=rr-p[pr];
                if(lb!=inf) an+=rb-p[pr];
            }
            else
            {
                int v1=p[yk]-p[pr], mr=0, mb=0, prr=p[pr], prb=p[pr];
                for(int a=pr+1; a<yk; a++)
                {
                    if(co[a]=='R')
                    {
                        mr=max(mr, p[a]-prr), prr=p[a];
                    }
                    else
                    {
                        mb=max(mb, p[a]-prb), prb=p[a];
                    }
                }
                mr=max(mr, p[yk]-prr), mb=max(mb, p[yk]-prb);
                v1+=(p[yk]-p[pr])*2-mr-mb;
                if(lr!=inf and lb!=inf) v1=min(v1, (p[yk]-p[pr])*2);
                an+=v1;
            }
            pr=yk, yk++;
        }
        else
        {
            if(lr!=inf) an+=rr-lr;
            if(lb!=inf) an+=rb-lb;
        }
    }
    cout<<an;
}