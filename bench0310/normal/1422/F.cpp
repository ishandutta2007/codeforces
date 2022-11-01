#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
const int N=200000;

struct opt
{
    vector<vector<int>> nxt;
    int mx;
    void ini(vector<int> a)
    {
        int n=a.size()-1;
        mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,a[i]);
        nxt.assign(n+1,vector<int>(mx+1,n+1));
        for(int i=n;i>=1;i--)
        {
            if(i<n) for(int j=1;j<=mx;j++) nxt[i][j]=nxt[i+1][j];
            nxt[i][a[i]]=i;
            for(int j=mx-1;j>=0;j--) nxt[i][j]=min(nxt[i][j],nxt[i][j+1]);
        }
    }
    int qry(int l,int r)
    {
        int one=0,two=mx+1;
        while(one<two-1)
        {
            int mid=(one+two)/2;
            if(nxt[l][mid]<=r) one=mid;
            else two=mid;
        }
        return one;
    }
};

struct Node
{
    int val;
    Node *l,*r;
    Node(int x){val=x;l=r=nullptr;}
    Node(Node *a,Node *b){l=a;r=b;val=((ll)l->val*r->val)%mod;}
};

Node* build(int l,int r)
{
    if(l==r) return new Node(1);
    else
    {
        int m=(l+r)/2;
        return new Node(build(l,m),build(m+1,r));
    }
}

Node* update(Node *now,int l,int r,int pos,int val)
{
    if(l==r) return new Node(val);
    int m=(l+r)/2;
    if(pos<=m) return new Node(update(now->l,l,m,pos,val),now->r);
    else return new Node(now->l,update(now->r,m+1,r,pos,val));
}

int query(Node *now,int l,int r,int ql,int qr)
{
    if(ql>qr) return 1;
    if(l==ql&&r==qr) return now->val;
    int m=(l+r)/2;
    return ((ll)query(now->l,l,m,ql,min(qr,m))*query(now->r,m+1,r,max(ql,m+1),qr))%mod;
}

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

ll inv(ll b)
{
    return fpow(b,mod-2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    const int lim=447;
    vector<int> small_primes;
    vector<int> h(lim+1,0);
    int hidx=1;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        if(i<=lim)
        {
            h[i]=hidx++;
            small_primes.push_back(i);
        }
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int n;
    cin >> n;
    vector<int> big(n+1,1);
    vector<vector<int>> small(hidx,vector<int>(n+1,0));
    vector<opt> st(hidx);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        vector<array<int,2>> p;
        while(1<sieve[a]&&sieve[a]<=lim)
        {
            p.push_back({sieve[a],0});
            while(sieve[a]==p.back()[0])
            {
                a/=sieve[a];
                p.back()[1]++;
            }
        }
        big[i]=a;
        for(auto [prime,pw]:p) small[h[prime]][i]=pw;
    }
    for(int i=1;i<hidx;i++) st[i].ini(small[i]);
    vector<int> nxt(N+1,n+1);
    vector<array<int,3>> val;
    for(int i=n;i>=1;i--)
    {
        if(nxt[big[i]]!=n+1) val.push_back({nxt[big[i]],i,big[i]});
        nxt[big[i]]=i;
    }
    sort(val.begin(),val.end());
    vector<Node*> root(n+1,nullptr);
    root[0]=build(1,n);
    Node *prv=root[0];
    for(auto [version,idx,num]:val)
    {
        root[version]=update(prv,1,n,idx,num);
        prv=root[version];
    }
    for(int i=1;i<=n;i++) if(root[i]==nullptr) root[i]=root[i-1];
    vector<int> m(n+1,1);
    for(int i=1;i<=n;i++) m[i]=((ll)m[i-1]*big[i])%mod;
    int q;
    cin >> q;
    int last=0;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int l=(x+last)%n+1;
        int r=(y+last)%n+1;
        if(l>r) swap(l,r);
        ll res=1;
        for(int prime:small_primes) res=(res*fpow(prime,st[h[prime]].qry(l,r)))%mod;
        res=(res*m[r])%mod;
        res=(res*inv(m[l-1]))%mod;
        res=(res*inv(query(root[r],1,n,l,r)))%mod;
        cout << res << "\n";
        last=res;
    }
    return 0;
}