#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<array<ll,2>> tree(4*N,{0,0});
vector<ll> lazy(4*N,0);
vector<int> h(N,0);
vector<int> depth(N,0);

void pull(int idx){tree[idx]=min(tree[2*idx],tree[2*idx+1]);}
void apply(int idx,ll x){tree[idx][0]+=x;lazy[idx]+=x;}
void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
    lazy[idx]=0;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]={depth[h[l]],h[l]};
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        pull(idx);
    }
}

void update(int idx,int l,int r,int ql,int qr,ll x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,x);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        pull(idx);
    }
}

array<ll,2> query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {(1<<30),0};
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s="$"+s;
    vector<array<int,2>> v(n+1,{0,0});
    for(int i=1;i<=n;i++) cin >> v[i][0] >> v[i][1];
    vector<int> tin(n+1,0);
    vector<int> tout(n+1,0);
    int tcnt=0;
    vector<int> in_order(n+1,0);
    vector<int> p(n+1,0);
    function<void(int)> dfs=[&](int a)
    {
        depth[a]=depth[p[a]]+1;
        tin[a]=tcnt+1;
        auto [l,r]=v[a];
        if(l)
        {
            p[l]=a;
            dfs(l);
        }
        in_order[a]=(++tcnt);
        h[tcnt]=a;
        if(r)
        {
            p[r]=a;
            dfs(r);
        }
        tout[a]=tcnt;
    };
    dfs(1);
    set<int> active;
    for(int i=1;i<=n;i++) active.insert(i);
    build(1,1,n);
    vector<bool> duplicate(n+1,0);
    auto rm=[&](int a)
    {
        update(1,1,n,in_order[a],in_order[a],(1<<30));
        active.erase(in_order[a]);
    };
    auto rm_range=[&](int tl,int tr)
    {
        while(1)
        {
            auto it=active.lower_bound(tl);
            if(it!=active.end()&&(*it)<=tr)
            {
                int a=h[*it];
                update(1,1,n,tin[a],tout[a],(1<<30));
                rm(a);
            }
            else break;
        }
    };
    int x=1;
    while(x<=n)
    {
        int y=x;
        char now=s[h[x]];
        while(y+1<=n&&s[h[y+1]]==now) y++;
        char nxt=(y==n?('a'-1):s[h[y+1]]);
        while(now<nxt)
        {
            auto [cnt,a]=query(1,1,n,x,y);
            if(cnt<=k)
            {
                while(active.contains(in_order[a]))
                {
                    duplicate[a]=1;
                    k--;
                    update(1,1,n,tin[a],tout[a],-1);
                    rm(a);
                    a=p[a];
                }
            }
            else break;
        }
        rm_range(x,y);
        x=y+1;
    }
    for(int i=1;i<=n;i++)
    {
        cout << s[h[i]];
        if(duplicate[h[i]]) cout << s[h[i]];
    }
    cout << "\n";
    return 0;
}