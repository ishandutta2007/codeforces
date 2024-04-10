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
    string s,t;
    cin >> s >> t;
    int n=s.size();
    int m=t.size();
    ranges::reverse(t);
    vector<mi> p[6][6];
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(i==j) continue;
            vector<mi> a(n);
            for(int k=0;k<n;k++) a[k]=(s[k]==char('a'+i));
            vector<mi> b(m);
            for(int k=0;k<m;k++) b[k]=(t[k]==char('a'+j));
            p[i][j]=conv(a,b);
        }
    }
    for(int i=0;i+m-1<n;i++)
    {
        vector<int> v[6];
        for(int x=0;x<6;x++)
        {
            for(int y=0;y<6;y++)
            {
                if(x==y) continue;
                if(p[x][y][i+m-1]!=0||p[y][x][i+m-1]!=0) v[x].push_back(y);
            }
        }
        int res=6;
        vector<bool> vis(6,0);
        function<void(int)> dfs=[&](int a)
        {
            vis[a]=1;
            for(int to:v[a]) if(!vis[to]) dfs(to);
        };
        for(int j=0;j<6;j++)
        {
            if(!vis[j])
            {
                res--;
                dfs(j);
            }
        }
        cout << res << " \n"[i+m-1==n-1];
    }
    return 0;
}