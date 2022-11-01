#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> a(N,0);
vector<int> tree(4*N,0);

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=a[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=gcd(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return gcd(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,w;
        cin >> n >> w;
        set<int> s;
        for(int i=1;i<n;i++) s.insert(i);
        vector<array<int,3>> edges;
        for(int i=1;i<n;i++) edges.push_back({w,i,i+1});
        vector<array<int,2>> v(n);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            v[i-1]={a[i],i};
        }
        sort(v.begin(),v.end());
        build(1,1,n);
        set<int> vis={0,n+1};
        for(auto [mn,i]:v)
        {
            auto it=vis.lower_bound(i);
            int limr=(*it);
            it--;
            int liml=(*it);
            vis.insert(i);
            int l=liml;
            int r=i;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(query(1,1,n,m,i)==mn) r=m;
                else l=m;
            }
            liml=r;
            l=i;
            r=limr;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(query(1,1,n,i,m)==mn) l=m;
                else r=m;
            }
            limr=l;
            while(1)
            {
                auto it2=s.lower_bound(liml);
                if(it2==s.end()||(*it2)>=limr) break;
                int x=(*it2);
                edges.push_back({mn,x,x+1});
                s.erase(it2);
            }
        }
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        vector<int> sz(n+1,1);
        function<int(int)> find_set=[&](int b)->int
        {
            if(b==p[b]) return b;
            else return p[b]=find_set(p[b]);
        };
        auto merge_sets=[&](int d,int e)->bool
        {
            d=find_set(d);
            e=find_set(e);
            if(d==e) return 0;
            if(sz[d]<sz[e]) swap(d,e);
            p[e]=d;
            sz[d]+=sz[e];
            return 1;
        };
        sort(edges.begin(),edges.end());
        ll res=0;
        for(auto [c,d,e]:edges)
        {
            if(merge_sets(d,e)) res+=c;
        }
        cout << res << "\n";
    }
    return 0;
}