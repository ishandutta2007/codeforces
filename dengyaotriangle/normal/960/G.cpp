#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

namespace comb{

const int mdn=998244353,g=3;
const int maxn=1<<22|1;
inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}

int x[maxn],y[maxn],brev[maxn],w[maxn];
int fac[maxn],ifac[maxn];
int facpt=0;

void initfac(int lim){
    if(facpt==0){fac[0]=ifac[0]=1;facpt=1;}
    while(facpt<lim){
        int rp=facpt<<1;
        for(int i=facpt;i<rp;i++){
            fac[i]=fac[i-1]*(long long)i%mdn;
        }
        ifac[rp-1]=qpw(fac[rp-1],mdn-2);
        for(int i=rp-1;i>facpt;i--)ifac[i-1]=ifac[i]*(long long)i%mdn;
        facpt<<=1;
    }
}
void iadd(int&a,int b){a+=b;if(a>=mdn)a-=mdn;}
void ineg(int&a){if(a)a=mdn-a;}
void ntt(int*a,int lg){
    int len=1<<lg;
    for(int i=0;i<len;i++)if(i<brev[i])swap(a[i],a[brev[i]]);
    for(int k=0;k<lg;k++){
        int r=lg-k-1,l=1<<k;
        for(int i=0;i<len;i+=l<<1){
            int*x=a+i,*y=a+(i|l);
            for(int j=0;j<l;j++,x++,y++){
                int tx=*x,ty=*y*(long long)w[j<<r]%mdn;
                *y=tx;iadd(*x,ty);iadd(*y,mdn-ty);
            }
        }
    }
}

vector<int> mul(const vector<int>&a,const vector<int>&b){
    int ta=a.size(),tb=b.size(),tl=ta+tb-1,lim=1,lg=0;
    while(lim<tl){lim<<=1;lg++;}
    for(int i=1;i<lim;i++)brev[i]=brev[i>>1]>>1|(i&1)<<(lg-1);
    int w0=qpw(g,(mdn-1)>>lg);
    w[0]=1;for(int i=1;i<lim;i++)w[i]=w[i-1]*(long long)w0%mdn;
    fill(x,x+lim,0);fill(y,y+lim,0);
    for(int i=0;i<ta;i++)x[i]=a[i];
    for(int i=0;i<tb;i++)y[i]=b[i];
    ntt(x,lg);ntt(y,lg);
    for(int i=0;i<lim;i++)x[i]=x[i]*(long long)y[i]%mdn;
    reverse(w+1,w+lim);
    ntt(x,lg);
    int inv=qpw(lim,mdn-2);
    vector<int> ret;ret.resize(tl);
    for(int i=0;i<tl;i++)ret[i]=x[i]*(long long)inv%mdn;
    return ret;
}

vector<int> bmul(const vector<int>&a,const vector<int>&b){
    vector<int> ret;ret.resize(a.size()+b.size()-1);
    for(int i=0;i<a.size();i++)for(int j=0;j<b.size();j++)iadd(ret[i+j],a[i]*(long long)b[j]%mdn);
    return ret;
}
inline vector<int> inv(const vector<int>&a){
    vector<int> ans;ans.resize(1);
    ans[0]=qpw(a[0],mdn-2);
    int lim=1,lg=0,n=a.size();
    while(lim<n){lim<<=1;lg++;}
    for(int i=2;i<=lim;i<<=1){
        vector<int> f=a;f.resize(i);
        vector<int> p1=mul(f,ans);
        p1.resize(i);
        p1[0]=(2+mdn-p1[0])%mdn;
        for(int j=1;j<i;j++)ineg(p1[j]);
        ans=mul(ans,p1);
        ans.resize(i);
    }
    ans.resize(n);return ans;
}

inline vector<int> deriv(const vector<int>&a){
    int n=a.size();
    vector<int> ans;ans.resize(n-1);
    for(int i=0;i<n-1;i++){ans[i]=a[i+1]*(long long)(i+1)%mdn;}
    return ans;
}

inline vector<int> integ(const vector<int>&a){
    int n=a.size();
    vector<int> ans;ans.resize(n+1);
    ans[0]=0;
    for(int i=1;i<=n;i++){ans[i]=a[i-1]*(long long)qpw(i,mdn-2)%mdn;}
    return ans;
}

inline vector<int> ln(const vector<int>&a){
    int n=a.size();
    vector<int> p1=integ(mul(deriv(a),inv(a)));
    p1.resize(n);return p1;
}

inline vector<int> exp(const vector<int>&a){
    vector<int> ans;ans.resize(1);ans[0]=1;
    int lim=1,lg=0,n=a.size();
    while(lim<n){lim<<=1;lg++;}
    for(int i=2;i<=lim;i<<=1){
        vector<int> sum=a;sum.resize(i);
        sum[0]=(sum[0]+1)%mdn;ans.resize(i);
        vector<int> lnx=ln(ans);
        for(int j=0;j<i;j++)iadd(sum[j],mdn-lnx[j]);
        ans=mul(sum,ans);
        ans.resize(i);
    }
    ans.resize(n);
    return ans;
}

inline vector<int> sqrt(const vector<int>&a){
    vector<int> ans;ans.resize(1);ans[0]=1;
    int lim=1,lg=0,n=a.size();
    while(lim<n){lim<<=1;lg++;}
    for(int i=2;i<=lim;i<<=1){
        vector<int> cur=a;cur.resize(i);
        ans.resize(i);
        vector<int> t=mul(inv(ans),cur);
        for(int j=0;j<i;j++)iadd(ans[j],t[j]);
        int inv2=(mdn+1)>>1;
        for(int j=0;j<i;j++)ans[j]=inv2*(long long)ans[j]%mdn;
    }
    ans.resize(n);return ans;
}

inline vector<int> qpow(const vector<int>&a,int ex){
    int lp=0,gp,n=a.size();
    for(int i=0;i<n;i++)if(a[i]){lp=i;gp=a[i];break;}
    int igp=qpw(gp,mdn-2);
    vector<int> tmp;tmp.resize(n-lp);for(int i=0;i<n-lp;i++)tmp[i]=a[i+lp]*(long long)igp%mdn;
    vector<int> e=ln(tmp);
    for(int i=0;i<e.size();i++)e[i]=e[i]*(long long)ex%mdn;
    tmp=exp(e);
    gp=qpw(gp,ex);
    vector<int> ret;ret.resize(n);
    if(lp*(long long)ex>=n)return ret;
    lp*=ex;
    for(int i=0;i<n-lp;i++)ret[i+lp]=tmp[i]*(long long)gp%mdn;
    return ret;
}
inline vector<int> qpowhuge(const vector<int>&a,string exs){
    int ex1=0,ex2=0;
    bool huge=0;
    for(int i=0;i<exs.size();i++){
        long long tmp= ex1*10ll+(exs[i]^'0');
        if(tmp>=mdn){huge=1;ex1=tmp%mdn;}
        else ex1=tmp;
        ex2=(ex2*10ll+(exs[i]^'0'))%(mdn-1);
    }
    int lp=0,gp,n=a.size();
    for(int i=0;i<n;i++)if(a[i]){lp=i;gp=a[i];break;}
    int igp=qpw(gp,mdn-2);
    vector<int> tmp;tmp.resize(n-lp);for(int i=0;i<n-lp;i++)tmp[i]=a[i+lp]*(long long)igp%mdn;
    vector<int> e=ln(tmp);
    for(int i=0;i<e.size();i++)e[i]=e[i]*(long long)ex1%mdn;
    tmp=exp(e);
    gp=qpw(gp,ex2);
    vector<int> ret;ret.resize(n);
    if(lp!=0&&huge||lp*(long long)ex1>=n)return ret;
    lp*=ex1;
    for(int i=0;i<n-lp;i++)ret[i+lp]=tmp[i]*(long long)gp%mdn;
    return ret;
}
inline vector<int> add(const vector<int>&a,const vector<int>&b){
    vector<int> ret=a;if(b.size()>a.size())ret.resize(b.size());
    for(int i=0;i<b.size();i++)iadd(ret[i],b[i]);
    return ret;
}
inline vector<int> minus(const vector<int>&a,const vector<int>&b){
    vector<int> ret=a;if(b.size()>a.size())ret.resize(b.size());
    for(int i=0;i<b.size();i++)iadd(ret[i],mdn-b[i]);
    return ret;
}
inline vector<int> shift(vector<int> a,int d){
    int n=a.size();
    initfac(n);
    vector<int> t;t.resize(n);t[0]=1;
    for(int i=1;i<n;i++)t[i]=t[i-1]*(long long)d%mdn;
    for(int i=2;i<n;i++)t[i]=t[i]*(long long)ifac[i]%mdn;
    for(int i=0;i<n;i++)a[i]=a[i]*(long long)fac[i]%mdn;
    reverse(a.begin(),a.end());
    a=mul(t,a);a.resize(n);
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++)a[i]=a[i]*(long long)ifac[i]%mdn;
    return a;
}

};

vector<int> calc(int c){
    if(c==0)return {1};
    if(c==1)return {0,1};
    int h=c/2;
    vector<int> w=calc(h);
    w=comb::mul(w,comb::shift(w,h));
    if(c&1){
        w=comb::bmul(w,{c-1,1});
    }
    return w;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    comb::initfac(n);
    vector<int> p=calc(n-1);
    int t=a+b-2;
    if(t>n){cout<<0;return 0;}
    cout<<p[t]*(long long)comb::fac[t]%comb::mdn*comb::ifac[a-1]%comb::mdn*comb::ifac[b-1]%comb::mdn;
    return 0;
}