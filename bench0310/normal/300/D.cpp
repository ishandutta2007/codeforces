#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=7340033;
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

vector<mi> pow4(vector<mi> &a)
{
    int sa=a.size();
    if(sa==0) return {};
    int n=1<<(32-__builtin_clz(4*(sa-1)));
    mi inv=1/mi(n);
    vector<mi> f(a),h(n);
    f.resize(n);
    ntt(f);
    for(int i=0;i<n;i++) h[(-i)&(n-1)]=(f[i]*f[i]*f[i]*f[i]*inv);
    ntt(h);
    h.resize(4*(sa-1)+1);
    return h;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=30;
    const int K=1000;
    vector<mi> v[N+1];
    v[0]={1};
    for(int i=1;i<=N;i++)
    {
        v[i]=pow4(v[i-1]);
        v[i].insert(v[i].begin(),1);
        while((int)v[i].size()>K+1) v[i].pop_back();
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int c=0;
        while(n>1&&(n&1))
        {
            c++;
            n=(n-1)/2;
        }
        int r=(((int)v[c].size()>=k+1)?int(v[c][k]):0);
        cout << r << "\n";
    }
    return 0;
}