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
    int n;
    cin >> n;
    vector<int> sz;
    int idx=1;
    auto out=[&](){cout << "0\n"; exit(0);};
    while(idx<=n)
    {
        int a;
        cin >> a;
        if(n-idx+1<a) out();
        for(int i=1;i<=a-1;i++)
        {
            int b;
            cin >> b;
            if(a!=b) out();
        }
        sz.push_back(a);
        idx+=a;
    }
    n=sz.size();
    auto add=[&](vector<mi> &a,vector<mi> &b)
    {
        vector<mi> c(max(a.size(),b.size()));
        for(int i=0;i<(int)a.size();i++) c[i]+=a[i];
        for(int i=0;i<(int)b.size();i++) c[i]+=b[i];
        return c;
    };
    auto madd=[&](vector<mi> &a,vector<mi> b){a=add(a,b);};
    mi inv2=inv(mi(2));
    function<vector<vector<mi>>(int,int)> go=[&](int l,int r)
    {
        vector res(4,vector<mi>());
        if(l==r)
        {
            if(sz[l]==1) res[0]={1};
            else res[3]={2};
            return res;
        }
        int m=(l+r)/2;
        auto tmp_one=go(l,m);
        auto tmp_two=go(m+1,r);
        for(int tl=0;tl<2;tl++)
        {
            for(int tr=0;tr<2;tr++)
            {
                //don't merge
                vector<mi> one=add(tmp_one[2*tl],tmp_one[2*tl+1]);
                vector<mi> two=add(tmp_two[tr],tmp_two[2+tr]);
                madd(res[2*tl+tr],conv(one,two));
                //merge
                for(int x=0;x<2;x++)
                {
                    for(int y=0;y<2;y++)
                    {
                        vector<mi> tmp=conv(tmp_one[2*tl+x],tmp_two[2*y+tr]);
                        tmp.insert(tmp.begin(),0);
                        for(mi &a:tmp)
                        {
                            if(x+y==0) a*=2;
                            if(x+y==2) a*=inv2;
                        }
                        int sl=tl,sr=tr;
                        if(l==m&&sz[l]==1) sl=1;
                        if(m+1==r&&sz[r]==1) sr=1;
                        madd(res[2*sl+sr],tmp);
                    }
                }
            }
        }
        return res;
    };
    auto tmp=go(0,n-1);
    vector<mi> res;
    for(int i=0;i<4;i++) madd(res,tmp[i]);
    mi r=0;
    vector<mi> f(n+1,1);
    for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
    for(int i=0;i<(int)res.size();i++)
    {
        mi t=res[i]*f[n-i];
        if((i%2)==0) r+=t;
        else r-=t;
    }
    cout << r << "\n";
    return 0;
}