#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

///const int N=300000+5;
const int L=1000000+5;

int n,k;
int f[L];

int ask(int st,int dr)
{
    if(st==0)
    {
        return f[dr];
    }
    else
    {
        return f[dr]-f[st-1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    int ma=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        f[x]++;
        ma=max(ma,x);
    }
    for(int i=1;i<L;i++)
    {
        f[i]+=f[i-1];
    }
    for(int x=ma;x>=1;x--)
    {
        int s=0;
        for(int st=x;st<L;st+=x)
        {
            int dr=st+k;
            if(dr>=st+x) dr=st+x-1;
            if(dr>=L) dr=L-1;
            s+=ask(st,dr);
        }
        if(s==n)
        {
            cout<<x<<"\n";
            return 0;
        }
    }
    return 0;
}