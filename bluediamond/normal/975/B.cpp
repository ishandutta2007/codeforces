#include <bits/stdc++.h>

using namespace std;

const long long N=30;
long long v[N+5],aux[N+5];
long long best=0;

void sim(long long poz)
{
    for(long long i=0;i<14;i++)
        aux[i]=v[i];
    aux[poz]=0;
    long long nr=v[poz];
    for(long long i=0;i<14;i++)
        aux[i]+=nr/14;
    long long p=poz+1;
    for(long long j=1;j<=nr%14;j++)
    {
        aux[p%14]++;
        p++;
    }
    long long cur=0;
    for(long long i=0;i<14;i++)
        if(aux[i]%2==0)
            cur+=aux[i];
    best=max(best,cur);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    for(long long i=0;i<14;i++)
        cin>>v[i];
    for(long long i=0;i<14;i++)
        sim(i);
    cout<<best;
    return 0;
}