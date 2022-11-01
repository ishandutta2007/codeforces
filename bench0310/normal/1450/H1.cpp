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
    int n,_m;
    cin >> n >> _m;
    string s;
    cin >> s;
    auto madd=[&](vector<mi> &a,vector<mi> &b)
    {
        if(a.size()<b.size()) a.resize(b.size());
        for(int i=0;i<(int)b.size();i++) a[i]+=b[i];
    };
    auto add_pos=[&](vector<mi> &a,int p,mi x)
    {
        if((int)a.size()-1<p) a.resize(p+1);
        a[p]+=x;
    };
    auto norm=[&](vector<mi> &a){while(!a.empty()&&a.back()==0)a.pop_back();};
    function<pair<vector<vector<mi>>,mi>(int,int)> go=[&](int l,int r)->pair<vector<vector<mi>>,mi>
    {
        vector v(4,vector<mi>());
        if(l==r)
        {
            if(s[l]=='b'||s[l]=='?') v[0]={0,1};
            if(s[l]=='w'||s[l]=='?') v[3]={0,1};
            return {v,0};
        }
        int m=(l+r)/2;
        auto [tmp_one,zero_one]=go(l,m);
        auto [tmp_two,zero_two]=go(m+1,r);
        mi zero=zero_one*zero_two;
        for(int x=0;x<2;x++)
        {
            for(int y=0;y<2;y++)
            {
                auto tmp=tmp_one[2*x+y];
                for(mi &a:tmp) a*=zero_two;
                madd(v[2*x+y],tmp);
                tmp=tmp_two[2*x+y];
                for(mi &a:tmp) a*=zero_one;
                madd(v[2*x+y],tmp);
            }
        }
        for(int lx=0;lx<2;lx++)
        {
            for(int ly=0;ly<2;ly++)
            {
                for(int rx=0;rx<2;rx++)
                {
                    for(int ry=0;ry<2;ry++)
                    {
                        auto &one=tmp_one[2*lx+ly];
                        auto &two=tmp_two[2*rx+ry];
                        if(ly!=rx)
                        {
                            auto tmp=conv(one,two);
                            madd(v[2*lx+ry],tmp);
                        }
                        else
                        {
                            int szb=two.size();
                            ranges::reverse(two);
                            auto tmp=conv(one,two);
                            ranges::reverse(two);
                            for(int i=0;i<(int)tmp.size();i++)
                            {
                                int d=i-(szb-1);
                                if(d>0) add_pos(v[2*lx+(lx^1^(d&1))],d,tmp[i]);
                                if(d<0) add_pos(v[2*(ry^1^(d&1))+ry],-d,tmp[i]);
                                if(d==0) zero+=tmp[i];
                            }
                        }
                    }
                }
            }
        }
        for(auto &u:v) norm(u);
        return {v,zero};
    };
    auto [tmp,zero]=go(0,n-1);
    vector<mi> p;
    for(int i=0;i<4;i++) madd(p,tmp[i]);
    mi sum=0;
    mi all=zero;
    for(int i=4;i<(int)p.size();i+=4)
    {
        sum+=mi(i/4)*p[i];
        all+=p[i];
    }
    cout << sum/all << "\n";
    return 0;
}