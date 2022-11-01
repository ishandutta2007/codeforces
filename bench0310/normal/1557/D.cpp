#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=600005;
vector<array<int,2>> tree(4*N,{0,0});
vector<array<int,2>> lazy(4*N,{0,0});

void apply(int idx,array<int,2> a)
{
    tree[idx]=max(tree[idx],a);
    lazy[idx]=max(lazy[idx],a);
}

void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
}

void update(int idx,int l,int r,int ql,int qr,array<int,2> a)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,a);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),a);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,a);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

array<int,2> query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v[n+1];
    vector<array<int,4>> h;
    for(int i=0;i<m;i++)
    {
        int x,l,r;
        cin >> x >> l >> r;
        h.push_back({l,x,(int)v[x].size(),0});
        h.push_back({r,x,(int)v[x].size(),1});
        v[x].push_back({l,r});
    }
    sort(h.begin(),h.end());
    int id=1;
    for(int i=0;i<2*m;i++)
    {
        if(i>0&&h[i][0]!=h[i-1][0]) id++;
        v[h[i][1]][h[i][2]][h[i][3]]=id;
    }
    vector<array<int,2>> best(n+1,{0,0});
    array<int,2> opt={0,0};
    for(int i=1;i<=n;i++)
    {
        for(auto [l,r]:v[i]) best[i]=max(best[i],query(1,1,id,l,r));
        best[i][0]++;
        for(auto [l,r]:v[i]) update(1,1,id,l,r,{best[i][0],i});
        opt=max(opt,{best[i][0],i});
    }
    vector<bool> vis(n+1,0);
    int x=opt[1];
    while(x>0)
    {
        vis[x]=1;
        x=best[x][1];
    }
    cout << n-opt[0] << "\n";
    for(int i=1;i<=n;i++) if(vis[i]==0) cout << i << " ";
    cout << "\n";
    return 0;
}