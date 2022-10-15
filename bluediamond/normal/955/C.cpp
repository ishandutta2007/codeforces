#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

const long long INF=1000000000000000000;
const long long N=1234567;/// 20
long long aux[N+5],v[N+5],y=0;

void gen()
{
    long long y_x=0;
    for(long long val=2;val*val*val<=INF;val++)
    {
        long long rad=sqrt(val);
        if(rad*rad==val)
            continue;
        long long sl=val*val*val;
        long long nr=3;
        while(1)
        {
            if(nr%2==1)
                aux[++y_x]=sl;
            long long bef=sl;
            sl*=val;
            if(bef==0)break;
            if(sl>INF || sl%bef!=0 || sl/bef!=val)
                break;
            nr++;
        }
    }
    aux[++y_x]=1;
    sort(aux+1,aux+y_x+1);
    v[++y]=aux[1];
    for(long long i=2;i<=y_x;i++)
        if(aux[i]!=aux[i-1])
            v[++y]=aux[i];
}

long long pre(long long val)
{
    if(val==0)
        return 0;
    long long sol=(long long)sqrt((long double)val);
    long long r=0,pas=(1<<20);
    while(pas)
    {
        if(r+pas<=y && val>=v[r+pas])
            r+=pas;
        pas/=2;
    }
    sol+=r;
    sol--;
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gen();
    long long q;
    cin>>q;
    while(q--)
    {
        long long a,b;
        cin>>a>>b;
        cout<<pre(b)-pre(a-1)<<"\n";
    }
    return 0;
}
/**
1
387291074607832779 798305191127761550
1000000000000000000
**/