#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
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

void ntt(vector<mi> &a)
{
    int n=a.size(),L=31-__builtin_clz(n);
    vector<int> rev(n);
    for(int i=0;i<n;i++) rev[i]=(rev[i/2]+((i&1)<<L))/2;
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    static vector<mi> rt(2,1);
    for(static int k=2,s=2;k<n;k*=2,s++)
    {
        rt.resize(n);
        mi z=pow(mi(3),mod>>s);
        for(int i=k;i<2*k;i++) rt[i]=rt[i/2]*((i&1)?z:1);
    }
    for(int k=1;k<n;k*=2)
    {
        for(int i=0;i<n;i+=2*k)
        {
            for(int j=0;j<k;j++)
            {
                mi z=rt[j+k]*a[i+j+k];
                a[i+j+k]=a[i+j]-z;
                a[i+j]+=z;
            }
        }
    }
}

vector<mi> conv(vector<mi> &a,vector<mi> &b)
{
    int sa=a.size(),sb=b.size();
    if(sa==0||sb==0) return {};
    int n=1<<(32-__builtin_clz(sa+sb-2));
    mi inv=1/mi(n);
    vector<mi> f(a),g(b),h(n);
    f.resize(n); g.resize(n);
    ntt(f); ntt(g);
    for(int i=0;i<n;i++) h[(-i)&(n-1)]=(f[i]*g[i]*inv);
    ntt(h);
    h.resize(sa+sb-1);
    return h;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    const int N=1000;
    vector<mi> v(N+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        v[a]=1;
    }
    vector<mi> res={1};
    int e=k;
    while(e)
    {
        if(e&1)
        {
            res=conv(res,v);
            for(mi &m:res) if(m!=0) m=1;
        }
        v=conv(v,v);
        for(mi &m:v) if(m!=0) m=1;
        e/=2;
    }
    for(int i=1;i<=k*N;i++) if(res[i]==1) cout << i << " ";
    cout << "\n";
    return 0;
}