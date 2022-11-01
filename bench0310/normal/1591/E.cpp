#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int x)
{
    if(l==r) tree[idx]+=x;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,x);
        else update(2*idx+1,m+1,r,pos,x);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int descend(int idx,int l,int r,int k)
{
    if(l==r) return l;
    int m=(l+r)/2;
    if(tree[2*idx]>=k) return descend(2*idx,l,m,k);
    else return descend(2*idx+1,m+1,r,k-tree[2*idx]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        vector<int> x(n+1,0);
        for(int i=1;i<=n;i++) cin >> x[i];
        vector<int> v[n+1];
        for(int i=2;i<=n;i++)
        {
            int p;
            cin >> p;
            v[p].push_back(i);
        }
        vector<array<int,3>> queries[n+1]; //l,k,id
        vector<int> res(q+1,0);
        for(int i=1;i<=q;i++)
        {
            int a,l,k;
            cin >> a >> l >> k;
            queries[a].push_back({l,k,i});
        }
        set<int> s[n+1];
        update(1,0,n,0,n);
        vector<int> occ(n+1,0);
        auto ch=[&](int a,int d)
        {
            int &o=occ[a];
            if(o>0) s[o].erase(a);
            update(1,0,n,o,-1);
            o+=d;
            if(o>0) s[o].insert(a);
            update(1,0,n,o,1);
        };
        function<void(int)> dfs=[&](int a)
        {
            ch(x[a],1);
            for(auto [l,k,id]:queries[a])
            {
                int c=query(1,0,n,0,l-1);
                if(n-c>=k) res[id]=(*s[descend(1,0,n,c+k)].begin());
                else res[id]=-1;
            }
            for(int to:v[a]) dfs(to);
            ch(x[a],-1);
        };
        dfs(1);
        update(1,0,n,0,-n);
        for(int i=1;i<=q;i++) cout << res[i] << " \n"[i==q];
    }
    return 0;
}