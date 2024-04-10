#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    ll k=0,n=0;
    ll lazyk=0,lazyn=0;
    void pull(Node &one,Node &two)
    {
        k=one.k+two.k;
        n=one.n+two.n;
    }
    void apply(ll uk,ll un,int l,int r)
    {
        k+=(r-l+1)*uk;
        n+=(r-l+1)*un;
        lazyk+=uk;
        lazyn+=un;
    }
    void push(int l,int r,Node &one,Node &two)
    {
        int m=(l+r)/2;
        one.apply(lazyk,lazyn,l,m);
        two.apply(lazyk,lazyn,m+1,r);
        lazyk=lazyn=0;
    }
    ll eval(int x){return (k*x+n);}
};

const int N=200005;
vector<Node> tree(4*N);

void update(int idx,int l,int r,int ql,int qr,ll valk,ll valn)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) tree[idx].apply(valk,valn,l,r);
    else
    {
        int m=(l+r)/2;
        tree[idx].push(l,r,tree[2*idx],tree[2*idx+1]);
        update(2*idx,l,m,ql,min(qr,m),valk,valn);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,valk,valn);
        tree[idx].pull(tree[2*idx],tree[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx].eval(x);
    int m=(l+r)/2;
    tree[idx].push(l,r,tree[2*idx],tree[2*idx+1]);
    return query(2*idx,l,m,ql,min(qr,m),x)+query(2*idx+1,m+1,r,max(ql,m+1),qr,x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> p(n+2,0);
    vector<int> pos(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
        pos[p[i]]=i;
    }
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=n;i++)
    {
        if(i>1) v[i].push_back({pos[1],pos[1]});
        for(int j=2;i*j<=n&&j<i;j++)
        {
            v[i*j].push_back({min(pos[i],pos[j]),max(pos[i],pos[j])});
        }
    }
    vector<int> lup(n+1,0);
    vector<int> rup(n+1,0);
    stack<int> s;
    p[0]=p[n+1]=n+1;
    s.push(0);
    for(int i=1;i<=n;i++)
    {
        while(p[s.top()]<p[i]) s.pop();
        lup[p[i]]=s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n+1);
    for(int i=n;i>=1;i--)
    {
        while(p[s.top()]<p[i]) s.pop();
        rup[p[i]]=s.top();
        s.push(i);
    }
    vector<array<int,4>> e[n+2];
    auto add_rectangle=[&](int x1,int x2,int y1,int y2)
    {
        e[x1].push_back({y1,y2,1,-(x1-1)});
        e[x2+1].push_back({y1,y2,-1,x2});
    };
    for(int i=1;i<=n;i++)
    {
        vector<array<int,2>> lstuff;
        int lfull=lup[i];
        int rfull=rup[i];
        for(auto [l,r]:v[i])
        {
            if(lup[i]<l&&l<pos[i]&&r>pos[i]) lstuff.push_back({l,r});
            if(l<pos[i]&&r<pos[i])
            {
                lfull=max(lfull,min(l,r));
                if(lup[i]<l) lstuff.push_back({l,rup[i]});
            }
            if(l>pos[i]&&r>pos[i]) rfull=min(rfull,max(l,r));
        }
        lstuff.push_back({pos[i],rup[i]});
        lstuff.push_back({lup[i],rup[i]});
        ranges::sort(lstuff,greater<>());
        int sz=lstuff.size();
        int opt=rfull;
        for(int j=0;j+1<sz;j++)
        {
            int one=lstuff[j+1][0]+1;
            int two=lstuff[j][0];
            if(one<=lfull) opt=pos[i];
            opt=min(opt,lstuff[j][1]);
            if(opt<=rup[i]-1) add_rectangle(one,two,opt,rup[i]-1);
        }
    }
    vector<array<int,4>> queries[n+1]; //l,r,d,id
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin >> x >> y;
        queries[x-1].push_back({x,y,-1,i});
        queries[y].push_back({x,y,1,i});
    }
    vector<ll> res(q+1,0);
    for(int i=0;i<=n;i++)
    {
        for(auto [l,r,uk,un]:e[i]) update(1,1,n,l,r,uk,un);
        for(auto [l,r,d,id]:queries[i]) res[id]+=(d*query(1,1,n,l,r,i));
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}