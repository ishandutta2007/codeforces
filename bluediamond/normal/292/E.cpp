#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;

int n,m;

int a[N],b[N];
int x[N],y[N],k[N];

int id[4*N];

void upd(int v,int tl,int tr,int l,int r,int x)
{
        ///cout<<v<<" : "<<tl<<" "<<tr<<"\n";
        if(tr<l || r<tl) return;
        if(l<=tl && tr<=r)
        {
                id[v]=x;
                return;
        }
        if(id[v])
        {
                id[2*v]=id[2*v+1]=id[v];
                id[v]=0;
        }
        int m=(tl+tr)>>1;
        upd(2*v,tl,m,l,r,x);
        upd(2*v+1,m+1,tr,l,r,x);
}

int get(int v,int tl,int tr,int p)
{
       /// cout<<tl<<" , "<<tr<<" : "<<id[v]<<"\n";
        if(tr<p || p<tl) return 0;
        if(tl==tr)
        {
                return id[v];
        }
        if(id[v])
        {
                id[2*v]=id[2*v+1]=id[v];
                id[v]=0;
        }
        int m=(tl+tr)>>1;
        return get(2*v,tl,m,p)+get(2*v+1,m+1,tr,p);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ///freopen("data.in","r",stdin);
        ///freopen("data.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
                cin>>b[i];
        }
        for(int i=1;i<=m;i++)
        {
                int ty;
                cin>>ty;
                if(ty==2)
                {
                        int p;
                        cin>>p;
                        int id=get(1,1,n,p);
                        if(id==0)
                        {
                                cout<<b[p]<<"\n";
                        }
                        else
                        {
                                int dif=p-y[id]+1;
                                cout<<a[x[id]+dif-1]<<"\n";
                        }
                }
                else
                {
                        cin>>x[i]>>y[i]>>k[i];
                        upd(1,1,n,y[i],y[i]+k[i]-1,i);
                }
        }

        return 0;
}
/**

**/