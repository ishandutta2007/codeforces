#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;

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
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
};

const int N=200000;
vector<int> tree(4*(N+5),0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]+=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++) cin >> s[i];
    vector<int> t(m+1,0);
    for(int i=1;i<=m;i++) cin >> t[i];
    vector<mi> f(n+1,1);
    for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
    vector<mi> finv(n+1,1); finv[n]=inv(f[n]);
    for(int i=n;i>=1;i--) finv[i-1]=finv[i]*mi(i);
    auto C=[&](int a,int b)->mi{return (f[a]*finv[b]*finv[a-b]);};
    vector<int> a(N+1,0);
    for(int i=1;i<=n;i++)
    {
        a[s[i]]++;
        update(1,1,N,s[i],1);
    }
    vector<int> c(N+1,0);
    mi now=1;
    mi res=0;
    for(int i=1;i<=min(n+1,m);i++) //first smaller
    {
        if(i>=2)
        {
            int p=t[i-1];
            now/=(C(a[p],c[p])*f[c[p]]);
            c[p]++;
            if(c[p]>a[p]) break;
            now*=(C(a[p],c[p])*f[c[p]]);
            update(1,1,N,p,-1);
        }
        int o=query(1,1,N,1,t[i]-1);
        if(i==n+1) o=1;
        res+=(now*mi(o)*(i<=n?f[n-i]:mi(1)));
    }
    for(int i=1;i<=N;i++) res*=finv[a[i]];
    cout << res << "\n";
    return 0;
}