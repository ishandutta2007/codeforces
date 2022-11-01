#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200000;
map<int,int> tree[4*(N+5)];

void build(int idx,int l,int r)
{
    tree[idx][0]=0;
    if(l<r)
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
    }
}

void update(int idx,int l,int r,int pos,int x,int y)
{
    map<int,int> &m=tree[idx];
    auto it=m.upper_bound(x);
    it--;
    if((*it).second<y)
    {
        m[x]=y;
        while(1)
        {
            it=m.upper_bound(x);
            if(it==m.end()||y<(*it).second) break;
            m.erase(it);
        }
    }
    if(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid) update(2*idx,l,mid,pos,x,y);
        else update(2*idx+1,mid+1,r,pos,x,y);
    }
}

int query(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr)
    {
        map<int,int> &m=tree[idx];
        auto it=m.lower_bound(x);
        it--;
        return (*it).second;
    }
    int mid=(l+r)/2;
    return max(query(2*idx,l,mid,ql,min(qr,mid),x),query(2*idx+1,mid+1,r,max(ql,mid+1),qr,x));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    build(1,0,N);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        int b=i-a;
        if(b<0) continue;
        int r=query(1,0,N,0,b,a)+1;
        res=max(res,r);
        update(1,0,N,b,a,r);
    }
    cout << res << "\n";
    return 0;
}