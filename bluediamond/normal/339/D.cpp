#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(1<<17)+7;

int n,q;
int t[4*N],h[4*N];

void build(int v,int tl,int tr)
{
        if(tl==tr)
        {
                h[v]=1;
        }
        else
        {
                int m=(tl+tr)>>1;
                build(2*v,tl,m);
                build(2*v+1,m+1,tr);
                h[v]=1+h[2*v];
        }
}

void upd(int v,int tl,int tr,int p,int x)
{
        if(tr<p || p<tl) return;
        if(tl==tr)
        {
                t[v]=x;
        }
        else
        {
                int m=(tl+tr)>>1;
                upd(2*v,tl,m,p,x);
                upd(2*v+1,m+1,tr,p,x);
                if(h[v]%2==0)
                {
                        t[v]=(t[2*v]|t[2*v+1]);
                }
                else
                {
                        t[v]=(t[2*v]^t[2*v+1]);
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>q;
        n=(1<<n);
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                upd(1,1,n,i,x);
        }
        while(q--)
        {
                int p,x;
                cin>>p>>x;
                upd(1,1,n,p,x);
                cout<<t[1]<<"\n";
        }
        return 0;
}