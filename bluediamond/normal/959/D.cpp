#include <iostream>
#include <set>

using namespace std;

const int N=1000000;
int n,v[N+5];
bool prime[N+5];
int p[N+5],y=0;
bool viz[N+5];

void build()
{
    for(int i=2;i<=N;i++)
        prime[i]=1;
    for(int i=4;i<=N;i+=2)
        prime[i]=0;
    for(int i=1;i*i<=N;i++)
        if(prime[i]==1)
            for(int j=i*i;j<=N;j+=2*i)
                prime[j]=0;
    for(int i=1;i<=N;i++)
        if(prime[i]==1)
            p[++y]=i;
}
int aux[N+5],l;
bool ok(int x)
{
    if(x<2)
        return 0;
    l=0;
    int ind=1;
    while(p[ind]*p[ind]<=x)
    {
        int nr=0;
        while(x%p[ind]==0)
        {
            x/=p[ind];
            nr++;
        }
        if(nr>=1)
            aux[++l]=p[ind];
        if(nr>=1 && viz[p[ind]]==1)
        {
            return 0;
        }
        ind++;
    }
    if(x>1 && viz[x]==1)
        return 0;
    if(x>1)
        aux[++l]=x;
    for(int i=1;i<=l;i++)
        viz[aux[i]]=1;
    return 1;
}
bool is_prime(int x)
{
    if(x<=1)
        return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    build();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
 //   cout<<v[1]<<"\n\n";
    int a=ok(v[1]);
    int poz=2;
    cout<<v[1]<<" ";
    while(poz<=n && ok(v[poz]))
    {
        cout<<v[poz]<<" ";
        poz++;
    }
    if(poz>n)
        return 0;
    while(!ok(v[poz]))
        v[poz]++;
    cout<<v[poz]<<" ";
    poz++;
    if(poz>n)
        return 0;
    for(int i=1;i<=N;i++)
        if(prime[i]==1 && viz[i]==0)
        {
            cout<<i<<" ";
            poz++;
            if(poz>n)
                return 0;
        }
    int val=N+1;
    while(1)
    {
        while(is_prime(val)==0)
            val++;
        cout<<val<<" ";
        val++;
        poz++;
        if(poz>n)
            return 0;
    }
    return 0;
}
/**
9
7 14 9 1 2 3 4 5 6
**/