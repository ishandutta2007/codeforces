#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
vector<int> treex(4*N,0);

void updatex(int idx,int l,int r,int pos,int val)
{
    if(l==r) treex[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) updatex(2*idx,l,m,pos,val);
        else updatex(2*idx+1,m+1,r,pos,val);
        treex[idx]=treex[2*idx]+treex[2*idx+1];
    }
}

int queryx(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return treex[idx];
    int m=(l+r)/2;
    return queryx(2*idx,l,m,ql,min(qr,m))+queryx(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int descendx(int idx,int l,int r,int x)
{
    if(l==r) return l;
    int m=(l+r)/2;
    if(treex[2*idx+1]>=x) return descendx(2*idx+1,m+1,r,x);
    else return descendx(2*idx,l,m,x-treex[2*idx+1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]=i-a[i];
    }
    vector<int> l(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            l[i]=i;
            updatex(1,1,n,i,1);
        }
        else if(a[i]>0)
        {
            if(treex[1]>=a[i])
            {
                l[i]=descendx(1,1,n,a[i]);
                updatex(1,1,n,l[i],1);
            }
        }
    }
    for(int i=0;i<4*N;i++) treex[i]=0;
    vector<int> rm[n+1];
    for(int i=1;i<=n;i++)
    {
        if(l[i]==-1) continue;
        //cout << i << " requires " << "[" << l[i] << "," << i << "]" << endl;
        rm[l[i]-1].push_back(i);
        updatex(1,1,n,i,1);
    }
    vector<array<int,2>> queries[n+1];
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin >> x >> y;
        queries[x].push_back({y,i});
    }
    vector<int> res(q+1,0);
    for(int i=0;i<=n;i++)
    {
        for(auto [y,id]:queries[i]) res[id]=queryx(1,1,n,1,n-y);
        for(int r:rm[i]) updatex(1,1,n,r,-1);
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}