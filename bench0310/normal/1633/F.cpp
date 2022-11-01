#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
int n;
ll tree[4*N];
int cnt[4*N];
int lazy[4*N];
ll sum[N];

void apply(int idx,int l,int r)
{
    tree[idx]=(sum[r]-sum[l-1]-tree[idx]);
    cnt[idx]=(r-l+1-cnt[idx]);
    lazy[idx]^=1;
}

void push(int idx,int l,int r,int m)
{
    if(lazy[idx]==1)
    {
        apply(2*idx,l,m);
        apply(2*idx+1,m+1,r);
        lazy[idx]=0;
    }
}

void pull(int idx)
{
    tree[idx]=tree[2*idx]+tree[2*idx+1];
    cnt[idx]=cnt[2*idx]+cnt[2*idx+1];
}

void update(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,l,r);
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        update(2*idx,l,m,ql,min(qr,m));
        update(2*idx+1,m+1,r,max(ql,m+1),qr);
        pull(idx);
    }
}

vector<array<int,2>> v[N];
int p[N];
int u[N];
int sz[N];
int big[N];
int pos[N];
int head[N];
int pcnt=0;

void dfs(int a)
{
    sz[a]=1;
    for(auto [to,c]:v[a])
    {
        if(to==p[a]) continue;
        p[to]=a;
        u[to]=c;
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

void decompose(int a,int h)
{
    pos[a]=(++pcnt);
    sum[pcnt]=sum[pcnt-1]+u[a];
    head[a]=h;
    if(big[a]!=0) decompose(big[a],h);
    for(auto [to,id]:v[a]) if(to!=p[a]&&to!=big[a]) decompose(to,to);
}

void flip(int a)
{
    while(a!=0)
    {
        update(1,1,n,pos[head[a]],pos[a]);
        a=p[head[a]];
    }
}

vector<int> res;

void descend(int idx,int l,int r)
{
    if(l==r)
    {
        if(tree[idx]>0) res.push_back(int(tree[idx]));
    }
    else
    {
        int m=(l+r)/2;
        push(idx,l,r,m);
        descend(2*idx,l,m);
        descend(2*idx+1,m+1,r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    dfs(1);
    decompose(1,1);
    flip(1);
    int active=1;
    while(1)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int a;
            cin >> a;
            flip(a);
            active++;
            if(2*cnt[1]==active) cout << tree[1] << endl;
            else cout << 0 << endl;
        }
        else if(t==2)
        {
            if(2*cnt[1]==active) descend(1,1,n);
            ranges::sort(res);
            cout << res.size() << "\n";
            for(int id:res) cout << id << " ";
            cout << endl;
            res.clear();
        }
        else break;
    }
    return 0;
}