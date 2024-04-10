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

void ntt(vector<mi> &a) //TODO: move inside the struct
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

vector<mi> conv(const vector<mi> &a,const vector<mi> &b) //TODO: move inside the struct
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

struct poly
{
    vector<mi> v;
    poly(){}
    poly(mi a){v={a};norm();}
    poly(vector<mi> u):v(u){norm();}
    friend int deg(const poly &p){return ((int)p.v.size()-1);}
    void norm(){while(!v.empty()&&v.back()==0)v.pop_back();}
    mi operator[](int idx)const{return ((0<=idx&&idx<=deg(*this))?v[idx]:0);}
    poly& operator+=(const poly &p)
    {
        v.resize(max(deg(*this),deg(p))+1);
        for(int i=0;i<=deg(p);i++) v[i]+=p[i];
        norm();
        return *this;
    }
    poly& operator-=(const poly &p)
    {
        v.resize(max(deg(*this),deg(p))+1);
        for(int i=0;i<=deg(p);i++) v[i]-=p[i];
        norm();
        return *this;
    }
    poly& operator*=(const poly &p){v=conv(v,p.v); norm(); return *this;}
    poly& operator/=(const poly &p){v=divmod(v,p)[0].v; norm(); return *this;}
    poly& operator%=(const poly &p){v=divmod(v,p)[1].v; norm(); return *this;}
    poly operator-()const{return poly()-(*this);}
    friend poly operator+(poly a,const poly &b){return a+=b;}
    friend poly operator-(poly a,const poly &b){return a-=b;}
    friend poly operator*(poly a,const poly &b){return a*=b;}
    friend poly operator/(poly a,const poly &b){return a/=b;}
    friend poly operator%(poly a,const poly &b){return a%=b;}
    poly& operator*=(const mi &m){for(mi& a:v)a*=m; return *this;}
    friend poly operator*(poly a,const mi &m){return a*=m;}
    poly mod_xk(int k)const{return poly(vector<mi>(v.begin(),v.begin()+min(k,deg(*this)+1)));}
    poly mul_xk(int k)const{poly p(v); p.v.insert(p.v.begin(),k,0); return p;}
    poly div_xk(int k)const{return poly(vector<mi>(v.begin()+min(k,deg(*this)+1),v.end()));}
    poly inv(int n)const
    {
        assert(!v.empty()&&v[0]!=0);
        poly b(1/v[0]);
        for(int s=1;s<n;s*=2) b=(b*(poly(2)-(*this).mod_xk(2*s)*b).mod_xk(2*s));
        return b.mod_xk(n);
    }
    poly rev(int n,bool unrev=0)const
    {
        poly p(v);
        if(unrev) p.v.resize(max(n,deg(p)+1));
        reverse(p.v.begin(),p.v.end());
        return p.mod_xk(n);
    }
    friend array<poly,2> divmod(const poly &a,const poly &b)
    {
        if(deg(a)<deg(b)) return {poly(0),a};
        int sz=deg(a)-deg(b);
        poly d=(a.rev(sz+1)*b.rev(sz+1).inv(sz+1)).mod_xk(sz+1).rev(sz+1,1);
        return {d,a-b*d};
    }
    poly deriv()
    {
        vector<mi> p;
        for(int i=1;i<=deg(*this);i++) p.push_back(mi(i)*v[i]);
        return poly(p);
    }
    poly sqrt(int n)
    {
        poly b(1); //TODO: implement sqrt modulo, currently only works for a0=1
        mi inv2=(1/mi(2));
        for(int s=1;s<n;s*=2) b=((b+((*this).mod_xk(2*s)*b.inv(2*s)).mod_xk(2*s))*inv2);
        return b.mod_xk(n);
    }
    vector<mi> multipoint_eval(vector<mi> p)
    {
        int n=p.size();
        vector<poly> tree(4*n);
        mp_eval_build(1,1,n,tree,p);
        mp_eval_go(1,1,n,poly(v),tree,p);
        return p;
    }
    friend void mp_eval_build(int idx,int l,int r,vector<poly> &tree,vector<mi> &p)
    {
        if(l==r) tree[idx]=poly({-p[l-1],1});
        else
        {
            int m=(l+r)/2;
            mp_eval_build(2*idx,l,m,tree,p);
            mp_eval_build(2*idx+1,m+1,r,tree,p);
            tree[idx]=tree[2*idx]*tree[2*idx+1];
        }
    }
    friend void mp_eval_go(int idx,int l,int r,poly a,vector<poly> &tree,vector<mi> &p)
    {
        a%=tree[idx];
        if(l==r) p[l-1]=(deg(a)==0?a[0]:0);
        else
        {
            int m=(l+r)/2;
            mp_eval_go(2*idx,l,m,a,tree,p);
            mp_eval_go(2*idx+1,m+1,r,a,tree,p);
        }
    }
    poly interpolate(vector<mi> x,vector<mi> y) //TODO: move outside the struct
    {
        int n=x.size();
        vector<poly> tree(4*n);
        mp_eval_build(1,1,n,tree,x);
        poly d=tree[1].deriv();
        vector<mi> t(n);
        mp_eval_go(1,1,n,d,tree,t);
        for(int i=0;i<n;i++) y[i]/=t[i];
        return interpolate_go(1,1,n,tree,y);
    }
    friend poly interpolate_go(int idx,int l,int r,vector<poly> &tree,vector<mi> &y)
    {
        if(l==r) return poly(y[l-1]);
        int m=(l+r)/2;
        poly one=interpolate_go(2*idx,l,m,tree,y);
        poly two=interpolate_go(2*idx+1,m+1,r,tree,y);
        return one*tree[2*idx+1]+two*tree[2*idx];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<mi> v(100001,0);
    for(int i=1;i<=n;i++)
    {
        int c;
        cin >> c;
        v[c]=1;
    }
    poly c(v);
    poly res=poly(2)*(poly(1)+(poly(1)-c*4).sqrt(m+1)).inv(m+1);
    for(int i=1;i<=m;i++) cout << res[i] << "\n";
    return 0;
}