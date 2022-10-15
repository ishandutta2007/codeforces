#include <bits/stdc++.h>

using namespace std;

const int N=200000+5;
int n,m,q,ap[N];
vector<int>vr[N];
vector<int>vc[N];
int comp[N],tbag[N];
set<int>s[N];

/// set

int t[N],h[N];

inline int FindSet(int nod)
{
    while(nod!=t[nod])
        nod=t[nod];
    return nod;
}

inline void UnionSet(int x,int y)
{
    x=FindSet(x);
    y=FindSet(y);
    if(x==y)
        return;
    if(h[x]==h[y])
    {
        h[x]++;
        t[y]=x;
        return;
    }
    if(h[x]>h[y])
        t[y]=x;
    if(h[x]<h[y])
        t[x]=y;
}

/// set

bool iscomp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    if(q==0)
    {
        cout<<n+m-1<<"\n";
        return 0;
    }
    for(int i=1;i<=q;i++)
    {
        int r,c;
        cin>>r>>c;
        ap[c]++;
        vr[r].push_back(c);
        vc[c].push_back(r);
    }
    for(int i=1;i<=n;i++)
    {
        t[i]=i;
        h[i]=1;
    }
    for(int col=1;col<=m;col++)
    {
        int sz=vc[col].size();
        for(int j=1;j<sz;j++)
        {
            UnionSet(vc[col][0],vc[col][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        comp[i]=FindSet(i);
        iscomp[comp[i]]=1;
    }
    int cnt_comp=0;
    int rgol=0,cgol=0;
    for(int i=1;i<=n;i++)
    {
        if(vr[i].size() && iscomp[i]==1)
        {
            cnt_comp++;
        }
        if(vr[i].size()==0)
            rgol++;
    }
    for(int i=1;i<=m;i++)
    {
        if(vc[i].size()==0)
            cgol++;
    }
    cout<<cgol+rgol+cnt_comp-1<<"\n";
    return 0;
}
/**
**/