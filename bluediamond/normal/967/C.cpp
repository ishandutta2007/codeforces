#include <bits/stdc++.h>

using namespace std;

const long long L=100000;
long long n,m;
long long n_scari,n_lift,v;
long long scari[L+5];
long long lift[L+5];

long long dist(long long a,long long b,long long c)
{
    if(a>c)
        swap(a,c);
    if(a<=b && b<=c)
        return c-a;
    if(b<a && a<=c)
        return a-b+c-b;
    if(a<=c && c<b)
        return b-a+b-c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>n_scari>>n_lift>>v;
    for(long long i=1;i<=n_scari;i++)
        cin>>scari[i];
    for(long long i=1;i<=n_lift;i++)
        cin>>lift[i];
    sort(scari+1,scari+n_scari+1);
    sort(lift+1,lift+n_lift+1);
    long long q;
    cin>>q;
    for(int nr_t=1;nr_t<=q;nr_t++)
    {
        long long r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        long long best=(1LL<<60);
        long long dif=abs(r1-r2);
        long long r,pas;
        if(r1==r2)
        {
            cout<<abs(c1-c2)<<"\n";
            continue;
        }
        r=-1;pas=(1<<20);
        while(pas)
        {
            if(r+pas<=n_scari && scari[r+pas]<=max(c2,c1))
                r+=pas;
            pas/=2;
        }
        for(long long j=r-5;j<=r+5;j++)
            if(1<=j && j<=n_scari)
                best=min(best,dif+dist(c1,scari[j],c2));
        r=-1;pas=(1<<20);
        while(pas)
        {
            if(r+pas<=n_lift && lift[r+pas]<=max(c2,c1))
                r+=pas;
            pas/=2;
        }
        long long dif2;
        if(dif%v==0)
            dif2=dif/v;
        else
            dif2=dif/v+1;
        for(long long j=r-5;j<=r+5;j++)
            if(1<=j && j<=n_lift)
                best=min(best,dif2+dist(c1,lift[j],c2));
        cout<<best<<"\n";
    }
    return 0;
}
/**

83 029 857


**/