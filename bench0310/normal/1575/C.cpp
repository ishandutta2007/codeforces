#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef complex<double> cd;
void fft(vector<cd> &a)
{
    int n=a.size(),L=31-__builtin_clz(n);
    vector<int> rev(n);
    for(int i=0;i<n;i++) rev[i]=(rev[i/2]+((i&1)<<L))/2;
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    static vector<complex<long double>> R(2,1);
    static vector<cd> rt(2,1);
    for(static int k=2;k<n;k*=2)
    {
        R.resize(n); rt.resize(n);
        auto z=polar(1.0L,acos(-1.0L)/k);
        for(int i=k;i<2*k;i++) rt[i]=R[i]=R[i/2]*((i&1)?z:1);
    }
    for(int k=1;k<n;k*=2)
    {
        for(int i=0;i<n;i+=2*k)
        {
            for(int j=0;j<k;j++)
            {
                cd z=rt[j+k]*a[i+j+k];
                a[i+j+k]=a[i+j]-z;
                a[i+j]+=z;
            }
        }
    }
}

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
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
};

vector<mi> conv_mod(vector<mi> &a,vector<mi> &b)
{
    int sa=a.size(),sb=b.size();
    if(sa==0||sb==0) return {};
    int n=1<<(32-__builtin_clz(sa+sb-2)),S=(1<<15);
    vector<cd> f(n),g(n),hs(n),hl(n);
    for(int i=0;i<sa;i++) f[i]=cd(int(a[i])&(S-1),(int(a[i])>>15));
    for(int i=0;i<sb;i++) g[i]=cd(int(b[i])&(S-1),(int(b[i])>>15));
    fft(f); fft(g);
    for(int i=0;i<n;i++)
    {
        int j=(-i)&(n-1);
        hs[i]=(f[j]+conj(f[i]))*g[j]/(2.0*n);
        hl[i]=(f[j]-conj(f[i]))*conj(g[i])/(2.0*n);
    }
    fft(hs); fft(hl);
    vector<mi> c(sa+sb-1);
    for(int i=0;i<sa+sb-1;i++)
    {
        ll ha=ll(real(hl[i])+0.5),hc=ll(real(hs[i])+0.5);
        ll hb=ll(imag(hl[i])+0.5)+ll(imag(hs[i])+0.5);
        c[i]=(ha*mi(S)+hb)*mi(S)+hc;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<mi> l(k,0);
    int s=0;
    for(int i=1;i<n;i++)
    {
        s=(s+a[i])%k;
        l[s]++;
    }
    vector<mi> r(k,0);
    s=0;
    for(int i=n;i>1;i--)
    {
        s=(s+a[i])%k;
        r[s]++;
    }
    vector<mi> p=conv_mod(l,r);
    for(int i=0;i<k-1;i++) p[i]+=p[i+k];
    s=(s+a[1])%k;
    auto go=[&](int tl,int tr,int val)->mi
    {
        mi now=0;
        vector<mi> cnt(k,0);
        cnt[0]++;
        int x=0;
        for(int i=tl;i<=tr;i++)
        {
            x=(x+a[i])%k;
            now+=cnt[(x-val+k)%k];
            cnt[x]++;
        }
        return now;
    };
    mi res=0;
    if(m==1)
    {
        //within
        res+=go(1,n,0);
        //wrap-around
        vector<mi> cnt(k,0);
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++)
        {
            sum[i]=(sum[i-1]+a[i])%k;
            if(i<n) cnt[sum[i]]++;
        }
        int tmp=0;
        for(int i=n;i>=3;i--)
        {
            tmp=(tmp+a[i])%k;
            cnt[sum[i-1]]--;
            res+=cnt[(k-tmp)%k];
        }
    }
    else
    {
        //at least one full segment
        for(int i=1;i<=m;i++)
        {
            int t=(k-((ll(i)*s)%k))%k;
            //both borders nice
            if(i>=2&&t==0) res+=(i<m?m:1);
            //one border nice
            if(i<=m-1) res+=(m*(l[t]+r[t]));
            //neither border nice
            if(i<=m-2) res+=(m*p[t]);
            if(i==m-1) res+=(m*go(2,n-1,(ll(m)*s)%k));
        }
        //wrap around one
        res+=(m*p[0]);
        //within a single array
        res+=(m*go(1,n,0));
    }
    cout << res << "\n";
    return 0;
}