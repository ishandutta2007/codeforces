#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000+5;

int n,k;
int p[N][17];

int lg[N];

int mul(int a,int b)
{
    return a*(long long)b%k;
}

int ask(int st,int dr)
{
    if(st>dr)
    {
        return 1;
    }
    int l=lg[dr-st+1];
    return mul(p[st][l],ask(st+(1<<l),dr));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=2;i<N;i++)
    {
        lg[i]=1+lg[i>>1];
    }
    /**
    cout<<lg[2]<<"\n";
    cout<<lg[3]<<"\n";
    cout<<lg[4]<<"\n";
    cout<<lg[5]<<"\n";
    cout<<lg[6]<<"\n";
    cout<<lg[7]<<"\n";
    cout<<lg[8]<<"\n";
    return 0;
    **/
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i][0];
    }
    for(int k=1;(1<<k)<=n;k++)
    {
        for(int st=1;st+(1<<k)-1<=n;st++)
        {
            p[st][k]=mul(p[st][k-1],p[st+(1<<(k-1))][k-1]);
        }
    }
    ll ans=0LL;
    int dr=1;
    for(int st=1;st<=n;st++)
    {
        if(dr<st)
        {
            dr=st;
        }
        while(dr+1<=n && ask(st,dr)!=0)
        {
            dr++;
        }
        if(ask(st,dr)==0)
        {
            ans+=(n+1-dr);
        }
    }
    cout<<ans<<"\n";
    return 0;
}