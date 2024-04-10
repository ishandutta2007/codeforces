#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=1000000007;

struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=(ll(v)*m.v)%mod; return *this;}
    mi& operator/=(const mi &m){return (*this)*=inv(m);}
    friend mi pow(mi a,ll e){mi r=1; for(;e;a*=a,e/=2)if(e&1)r*=a; return r;}
    friend mi inv(mi a){return pow(a,mod-2);}
    mi operator-()const{return mi(-v);}
    mi& operator++(){return (*this)+=1;}
    mi& operator--(){return (*this)-=1;}
    friend mi operator++(mi &a,int){mi t=a; ++a; return t;}
    friend mi operator--(mi &a,int){mi t=a; --a; return t;}
    friend mi operator+(mi a,const mi &b){return a+=b;}
    friend mi operator-(mi a,const mi &b){return a-=b;}
    friend mi operator*(mi a,const mi &b){return a*=b;}
    friend mi operator/(mi a,const mi &b){return a/=b;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

using num=array<mi,2>;
num operator+(num a,num b){return {a[0]+b[0],a[1]+b[1]};}
num operator-(num a){return {-a[0],-a[1]};}

const int N=200005;
int n;
vector<num> tree(4*N,{0,0});

void update(int idx,int l,int r,int pos,num x)
{
    tree[idx]=tree[idx]+x;
    if(l<r)
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,x);
        else update(2*idx+1,m+1,r,pos,x);
    }
}

void upd(array<int,2> t,num x)
{
    auto [l,r]=t;
    if(!(1<=l&&l<=r&&r<=n)) return;
    update(1,1,n,l,x);
    if(r+1<=n) update(1,1,n,r+1,-x);
}

num query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

num qry(int pos)
{
    return query(1,1,n,1,pos);
}

void nullify(int pos)
{
    upd({pos,pos},-qry(pos));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    vector<mi> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> b(n+1,0);
    vector<ll> s(n+1,0);
    vector<array<ll,2>> v(n);
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        s[i]=s[i-1]+b[i];
        v[i-1]={s[i-1],i};
    }
    ranges::sort(v);
    v.insert(v.begin(),{0,0});
    vector<ll> h(n,0);
    for(int i=1;i<=n;i++) h[i-1]=v[i][0];
    vector<int> pos(n+1,0);
    for(int i=1;i<=n;i++) pos[v[i][1]]=i;
    auto gr=[&](ll l,ll r)->array<int,2>
    {
        int x=ranges::lower_bound(h,l)-h.begin();
        int y=ranges::upper_bound(h,r)-h.begin()-1;
        return {x+1,y+1};
    };
    const ll inf=(1ll<<60);
    for(int i=1;i<=n;i++)
    {
        ll r=s[i-1];
        nullify(pos[i]);
        if(b[i]>0)
        {
            upd(gr(-inf,r),{-a[i]*b[i],0});
            upd(gr(r+1,r+b[i]),{-a[i]*b[i]-2*a[i]*r,-2*a[i]});
            upd(gr(r+b[i]+1,inf),{a[i]*b[i],0});
        }
        else
        {
            upd(gr(-inf,r+b[i]),{-a[i]*b[i],0});
            upd(gr(r+b[i]+1,r),{a[i]*b[i]+2*a[i]*r,2*a[i]});
            upd(gr(r+1,inf),{a[i]*b[i],0});
        }
    }
    vector<mi> res(n+2,0);
    for(int i=1;i<=n;i++)
    {
        auto [x,y]=qry(i);
        res[v[i][1]]=x-y*v[i][0];
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << res[l]-res[r+1] << "\n";
    }
    return 0;
}