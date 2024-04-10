#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1<<21|1;
const int mdn=998244353,g=3;

template<typename t,typename te,typename tm> inline t qpowm(t bse,te ex,tm mdn){t ans=(mdn!=1);while(ex){if(ex&1)ans=(ans*bse)%mdn;bse=(bse*bse)%mdn;ex>>=1;}return ans;}

int brev[maxn];
int gn[maxn];

inline void ntt(int*a,int tl,int t){
    for(int i=0;i<tl;i++)if(i<brev[i])swap(a[i],a[brev[i]]);
    for(int i=1;i<tl;i<<=1){
        int w=qpowm<long long>(g,(mdn-1)/2/i,mdn);if(t)w=qpowm<long long>(w,mdn-2,mdn);
        for(int j=0;j<tl;j+=(i<<1)){
            int wn=1;
            for(int k=j;k<j+i;k++){
                int x=a[k],y=1ll*a[k+i]*wn%mdn;
                a[k]=(x+y)%mdn;
                a[k+i]=(x+mdn-y)%mdn;
                wn=1ll*wn*w%mdn;
            }
        }
    }
    if(t){int inv=qpowm<long long>(tl,mdn-2,mdn);for(int i=0;i<tl;i++)a[i]=1ll*a[i]*inv%mdn;}
}

int x[maxn],y[maxn];

inline vector<int> plmul(const vector<int>&a,const vector<int>&b){
    int lim=1,lg=0;
    int n=a.size(),m=b.size();
    while(lim<n+m-1){lim<<=1;lg++;}
    memset(x,0,sizeof(int)<<lg);
    memset(y,0,sizeof(int)<<lg);
    for(int i=0;i<n;i++)x[i]=a[i];
    for(int i=0;i<m;i++)y[i]=b[i];
    for(int i=1;i<lim;i++)brev[i]=brev[i>>1]>>1|(i&1)<<(lg-1);
    ntt(x,lim,0);ntt(y,lim,0);
    for(int i=0;i<lim;i++)x[i]=1ll*x[i]*y[i]%mdn;
    ntt(x,lim,1);
    vector<int> ret;ret.resize(n+m-1);
    for(int i=0;i<n+m-1;i++)ret[i]=x[i];
    return ret;
}

inline vector<int> plinv(const vector<int>&a){
    vector<int> ans;ans.resize(1);
    ans[0]=qpowm<long long>(a[0],mdn-2,mdn);
    int lim=1,lg=0,n=a.size();
    while(lim<n){lim<<=1;lg++;}
    for(int i=1;i<lim;i<<=1){
        vector<int> f=a;f.resize(i<<1);
        vector<int> p1=plmul(f,ans);
        p1.resize(i<<1);
        p1[0]=(2+mdn-p1[0])%mdn;
        for(int j=1;j<(i<<1);j++)p1[j]=(mdn-p1[j])%mdn;
        ans=plmul(ans,p1);
        ans.resize(i<<1);
    }
    ans.resize(n);return ans;
}

inline vector<int> plderiv(const vector<int>&a){
    int n=a.size();
    vector<int> ans;ans.resize(n-1);
    for(int i=0;i<n-1;i++){ans[i]=1ll*a[i+1]*(i+1)%mdn;}
    return ans;
}

inline vector<int> plinteg(const vector<int>&a){
    int n=a.size();
    vector<int> ans;ans.resize(n+1);
    ans[0]=0;
    for(int i=1;i<=n;i++){ans[i]=a[i-1]*qpowm<long long>(i,mdn-2,mdn)%mdn;}
    return ans;
}

inline vector<int> plln(const vector<int>&a){
    int n=a.size();
    vector<int> p1=plinteg(plmul(plderiv(a),plinv(a)));
    p1.resize(n);return p1;
}

inline vector<int> plexp(const vector<int>&a){
    vector<int> ans;ans.resize(1);ans[0]=1;
    int lim=1,lg=0,n=a.size();
    while(lim<n){lim<<=1;lg++;}
    for(int i=1;i<lim;i<<=1){
        vector<int> sum=a;sum.resize(i<<1);
        sum[0]=(sum[0]+1)%mdn;ans.resize(i<<1);
        vector<int> ln=plln(ans);
        for(int j=0;j<(i<<1);j++)sum[j]=(sum[j]+mdn-ln[j])%mdn;
        ans=plmul(sum,ans);
        ans.resize(i<<1);
    }
    ans.resize(n);
    return ans;
}

inline vector<int> plsqrt(const vector<int>&a){
    vector<int> ans;ans.resize(1);ans[0]=1;
    int lim=1,lg=0,n=a.size();
    while(lim<n){lim<<=1;lg++;}
    for(int i=1;i<lim;i<<=1){
        vector<int> cur=a;cur.resize(i<<1);
        ans.resize(i<<1);
        vector<int> t=plmul(plinv(ans),cur);
        for(int j=0;j<(i<<1);j++)ans[j]=(ans[j]+t[j])%mdn;
        static const int inv2=(mdn+1)>>1;
        for(int j=0;j<(i<<1);j++)ans[j]=1ll*inv2*ans[j]%mdn;
    }
    ans.resize(n);return ans;
}
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    vector<int> c;c.resize(m+1);c[0]=1;
    for(int i=1;i<=n;i++){
        int f;cin>>f;if(f<=m)c[f]=(c[f]+mdn-4)%mdn;
    }
    vector<int> t=plsqrt(c);t[0]=(t[0]+1)%mdn;
    t=plinv(t);
    for(int i=0;i<=m;i++)t[i]=(t[i]<<1)%mdn;
    for(int i=1;i<=m;i++)cout<<t[i]<<'\n';
    return 0;
}