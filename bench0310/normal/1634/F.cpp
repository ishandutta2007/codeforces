#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mod;

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q >> mod;
    vector<array<mi,2>> a(n+2,{0,0});
    int c=n;
    vector<mi> t(n+1,0);
    for(int i=1;i<=2*n;i++)
    {
        mi b;
        cin >> b;
        if(i<=n) t[i]+=b;
        else t[i-n]-=b;
    }
    auto ch=[&](int i,int d)
    {
        if(0<=i&&i<n) c+=(d*(a[i][1]==-a[i+1][0]));
    };
    auto add=[&](int i,array<mi,2> b)
    {
        ch(i-1,-1); ch(i,-1);
        a[i][0]+=b[0]; a[i][1]+=b[1];
        ch(i-1,1); ch(i,1);
    };
    for(int i=1;i<=n;i++)
    {
        add(i,{t[i],0});
        add(i+1,{-t[i],-t[i]});
    }
    vector<mi> f(n+2,0);
    f[1]=1;
    for(int i=2;i<=n+1;i++) f[i]=f[i-1]+f[i-2];
    while(q--)
    {
        char tp;
        int l,r;
        cin >> tp >> l >> r;
        mi d=(tp=='A'?mi(1):mi(-1));
        add(l,{d*f[1],0});
        add(r+1,{-d*f[r-l+2],-d*f[r-l+1]});
        if(c==n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}