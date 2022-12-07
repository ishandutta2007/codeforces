#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e18, sz=1e3+10;
int st[sz][65], yk[65];
main()
{
    for(int a=1; a<sz; a++)
    {
        st[a][0]=1;
        for(int b=1; b<65; b++)
        {
            if(inf/st[a][b-1]<a) st[a][b]=inf;
            else st[a][b]=st[a][b-1]*a;
        }
    }
    for(int a=0; a<65; a++) yk[a]=1;
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    pair <int, int> ar[t];
    for(int i=0; i<t; i++)
    {
        scanf("%lld", &ar[i].first);
        ar[i].second=i;
    }
    sort(ar, ar+t);
    int an[t];
    for(int i=0; i<t; i++)
    {
        int n=ar[i].first, nu=ar[i].second, va[65];
        an[nu]=n-1;
        for(int a=64; a>5; a--)
        {
            while(st[yk[a]+1][a]<=n) yk[a]++;
            va[a]=yk[a]-1;
        }
        for(int a=5; a>=2; a--)
        {
            int l=1, r=2e9;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                int cu=mid, ok=1;
                for(int b=1; b<a; b++)
                {
                    if(n/cu<mid) ok=0;
                    else cu*=mid;
                }
                if(ok) l=mid;
                else r=mid;
            }
            va[a]=l-1;
        }
        for(int a=64; a>=2; a--)
        {
            for(int b=a+a; b<65; b+=a) va[a]-=va[b];
            an[nu]-=va[a];
        }
    }
    for(int a=0; a<t; a++) printf("%lld\n", an[a]);
}