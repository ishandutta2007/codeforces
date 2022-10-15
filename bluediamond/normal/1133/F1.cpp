#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

int n,m;
int a[N];
int b[N];
int sz[N];

int mx=0,nod;

int t[N];

int gt(int a)
{
        if(a==t[a])
        {
                return a;
        }
        else
        {
                t[a]=gt(t[a]);
                return t[a];
        }
}

void uni(int a,int b)
{
        a=gt(a);
        b=gt(b);
        if(a==b) return;
        t[a]=b;
}

bool take[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;i++) t[i]=i;
        for(int i=1;i<=m;i++)
        {
                cin>>a[i]>>b[i];
                sz[a[i]]++;
                sz[b[i]]++;
                mx=max(mx,sz[a[i]]);
                mx=max(mx,sz[b[i]]);
                if(sz[a[i]]==mx) nod=a[i];
                if(sz[b[i]]==mx) nod=b[i];
        }
        for(int i=1;i<=m;i++)
        {
                if(a[i]==nod || b[i]==nod)
                {
                        uni(a[i],b[i]);
                        take[i]=1;
                }
        }
        for(int i=1;i<=m;i++)
        {
                if(gt(a[i])!=gt(b[i]))
                {
                        take[i]=1;
                        uni(a[i],b[i]);
                }
        }
       /// cout<<"\n";
        for(int i=1;i<=m;i++)
        {
                if(take[i])
                {
                        cout<<a[i]<<" "<<b[i]<<"\n";
                }
        }
        return 0;
}
/**

**/