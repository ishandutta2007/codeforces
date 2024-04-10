#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;
const int primitive_root=3;

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
        mi z=pow(mi(primitive_root),mod>>s);
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
    const int S=2020;
    string s,t;
    cin >> s >> t;
    int n=s.size();
    int m=t.size();
    vector<mi> a(n);
    for(int i=0;i<n;i++) a[i]=(s[i]=='1'?1:-1);
    vector<mi> b(m);
    for(int i=0;i<m;i++) b[m-1-i]=(t[i]=='1'?1:-1);
    vector<vector<mi>> v;
    for(int i=0;i+S-1<n;i+=S)
    {
        vector<mi> tmp(a.begin()+i,a.begin()+i+S);
        v.push_back(conv(tmp,b));
    }
    ranges::reverse(b);
    int q;
    cin >> q;
    while(q--)
    {
        int la,lb,len;
        cin >> la >> lb >> len;
        int ra=la+len-1;
        int res=0;
        if(la/S==ra/S)
        {
            for(int i=0;i<len;i++) res+=(a[la+i]!=b[lb+i]);
        }
        else
        {
            int x=(la/S);
            int y=(ra/S);
            for(int i=la;i/S==x;i++) res+=(a[i]!=b[lb+i-la]);
            for(int i=ra;i/S==y;i--) res+=(a[i]!=b[lb+i-la]);
            for(int i=x+1;i<=y-1;i++)
            {
                int ta=i*S;
                int tb=lb+ta-la;
                int tmp=int(v[i][m-1-tb]);
                if(tmp>S) tmp-=mod;
                res+=(S-tmp)/2;
            }
        }
        cout << res << "\n";
    }
    return 0;
}