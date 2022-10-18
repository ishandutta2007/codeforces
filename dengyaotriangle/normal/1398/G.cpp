#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!
const int mdn=998244353,g=3;
const int maxn=1<<20|1;
int x[maxn],y[maxn],brev[maxn],w[maxn];

inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}
int norm(int a){return a>=mdn?a-mdn:a;}
void iadd(int&a,int b){a+=b;if(a>=mdn)a-=mdn;}
void ineg(int&a){if(a)a=mdn-a;}
void ntt(int*a,int lg){
    int len=1<<lg;
    for(int i=0;i<len;i++)if(i<brev[i])swap(a[i],a[brev[i]]);
    for(int k=0;k<lg;k++){
        int r=lg-k-1,l=1<<k;
        for(int i=0;i<len;i+=l<<1){
            int *const x=a+i,*const y=a+(i|l);
            for(int j=0;j<l;j++){
                int tx=x[j],ty=y[j]*(long long)w[j<<r]%mdn;
                iadd(x[j],ty);y[j]=norm(tx-ty+mdn);
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
    for(int i=0;i<ta;i++)x[i]=a[i];for(int i=ta;i<lim;i++)x[i]=0;
    for(int i=0;i<tb;i++)y[i]=b[i];for(int i=tb;i<lim;i++)y[i]=0;
    ntt(x,lg);ntt(y,lg);
    for(int i=0;i<lim;i++)x[i]=x[i]*(long long)y[i]%mdn;
    reverse(w+1,w+lim);
    ntt(x,lg);
    int inv=qpw(lim,mdn-2);
    vector<int> ret;ret.resize(tl);
    for(int i=0;i<tl;i++)ret[i]=x[i]*(long long)inv%mdn;
    return ret;
}

int n;
bool ok[maxn];
int ans[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x,y;
    cin>>n>>x>>y;
    vector<int> f(x+1);
    n++;
    for(int i=1;i<=n;i++){
        int u;cin>>u;
        f[u]++;
    }
    vector<int > g=f;
    reverse(g.begin(),g.end());
    vector<int> h=mul(f,g);
    int dlt=g.size()-1;
    for(int i=1;i<=x;i++){
        if(h[i+dlt])ok[i+y]=1;
    }
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<maxn;i++){
        if(ok[i]){
            for(int j=i;j<maxn;j+=i)ans[j]=i;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;x>>=1;
        if(ans[x]==-1)cout<<-1<<' ';
        else cout<<(ans[x]<<1)<<' ';
    }
    return 0;
}