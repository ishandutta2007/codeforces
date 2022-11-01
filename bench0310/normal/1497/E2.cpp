#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    int val;
    Node *l,*r;
    Node(int a){val=a;}
    Node(Node *a,Node *b){l=a;r=b;val=l->val+r->val;}
};

Node* build(int l,int r)
{
    if(l==r) return new Node(0);
    int m=(l+r)/2;
    return new Node(build(l,m),build(m+1,r));
}

Node* update(Node *now,int l,int r,int pos)
{
    if(l==r) return new Node(1);
    int m=(l+r)/2;
    if(pos<=m) return new Node(update(now->l,l,m,pos),now->r);
    else return new Node(now->l,update(now->r,m+1,r,pos));
}

int query(Node *now,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return now->val;
    int m=(l+r)/2;
    return query(now->l,l,m,ql,min(qr,m))+query(now->r,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=10000000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    const int K=20;
    auto odd=[&](int a)->vector<int>
    {
        vector<int> v;
        while(a>1)
        {
            int p=sieve[a];
            int pw=0;
            while((a%p)==0)
            {
                a/=p;
                pw^=1;
            }
            if(pw==1) v.push_back(p);
        }
        return v;
    };
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<pair<vector<int>,int>> h(n);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            h[i-1]={odd(a),i};
        }
        vector<int> a(n+1,0);
        sort(h.begin(),h.end());
        int id=1;
        for(int i=0;i<n;i++)
        {
            if(i>0&&h[i-1].first!=h[i].first) id++;
            a[h[i].second]=id;
        }
        vector<int> nxt(n+1,0);
        vector<int> pos(n+1,n+1);
        vector<array<int,2>> e(n);
        for(int i=n;i>=1;i--)
        {
            nxt[i]=pos[a[i]];
            pos[a[i]]=i;
            e[i-1]={nxt[i],i};
        }
        sort(e.begin(),e.end());
        vector<Node*> root(n+2,nullptr);
        root[0]=build(1,n);
        int idx=0;
        for(int i=1;i<=n+1;i++)
        {
            root[i]=root[i-1];
            while(idx<n&&e[idx][0]==i) root[i]=update(root[i],1,n,e[idx++][1]);
        }
        vector<array<int,K+1>> dp(n+2);
        dp[1].fill(0);
        for(int i=2;i<=n+1;i++) dp[i].fill(1<<30);
        array<int,K> r;
        r.fill(1);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                while(r[j]<n&&query(root[r[j]+1],1,n,i,r[j]+1)<=j) r[j]++;
                for(int x=0;x+j<=k;x++) dp[r[j]+1][x+j]=min(dp[r[j]+1][x+j],dp[i][x]+(r[j]+1<=n));
            }
        }
        cout << 1+dp[n+1][k] << "\n";
    }
    return 0;
}