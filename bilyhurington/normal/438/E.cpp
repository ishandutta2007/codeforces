#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,gen=3,MAXN=1600000;
namespace Polynomial{
    int fast_pow(int x,int k){
        long long ans=1;
        while(k){
            if(k&1) ans=(ans*x)%mod;
            x=(x*(long long)x)%mod;
            k>>=1;
        }
        return ans;
    }
    inline int mi(int x,int y){return x>=y?x-y:x-y+mod;}
    inline int pl(int x,int y){x+=y;return x>=mod?x-mod:x;}
    long long W[MAXN+10];
    void init_W(int n){
        long long tmp;
        for(int i=1;i<n;i<<=1){
            W[i]=1;tmp=fast_pow(3,(mod-1)/2/i);
            for(int j=1;j<=i-1;j++) W[i+j]=tmp*W[i+j-1]%mod;
        }
    }
    void NTT(int *a,int len,bool tag){
        int *b=new int[len];b[0]=0;
        for(int i=1;i<len;i++) b[i]=(b[i>>1]>>1)|((i&1)*(len>>1));
        for(int i=0;i<len;i++) if(i<b[i]) swap(a[i],a[b[i]]);
        for(int i=1;i<len;i<<=1){
            for(int j=0;j<len;j+=i<<1){
                for(int k=0;k<i;k++){
                    int t=a[i+j+k]*W[i+k]%mod;
                    a[i+j+k]=mi(a[j+k],t);
                    a[j+k]=pl(a[j+k],t);
                }
            }
        }
        if(tag){
            reverse(a+1,a+len);
            for(int i=0,inv=fast_pow(len,mod-2);i<len;i++) a[i]=a[i]*(long long)inv%mod;
        }
        delete []b;
    }
    void poly_mul(int *a,int *b,int len){
        int *c=new int[len<<1];
        for(int i=0;i<len;i++) c[i]=b[i];
        for(int i=len;i<(len<<1);i++) c[i]=0;
        NTT(c,len<<1,0);
        NTT(a,len<<1,0);
        for(int i=0;i<(len<<1);i++) a[i]=(long long)a[i]*c[i]%mod;
        NTT(a,len<<1,1);
        delete []c;
    }
    void poly_inv(int *a,int len){
        if(len==1){a[0]=fast_pow(a[0],mod-2);return;}
        int *c=new int[len<<1];
        for(int i=0;i<(len>>1);i++) c[i]=a[i];
        for(int i=len>>1;i<(len<<1);i++) c[i]=0;
        poly_inv(c,len>>1);
        for(int i=len>>1;i<(len<<1);i++) c[i]=0;
        NTT(a,len<<1,0);NTT(c,len<<1,0);
        for(int i=0;i<(len<<1);i++) a[i]=mi(pl(c[i],c[i]),(long long)a[i]*c[i]%mod*c[i]%mod);
        NTT(a,len<<1,1);
        for(int i=len;i<(len<<1);i++) a[i]=0;
        delete []c;
    }
    void poly_der(int *a,int len){
        for(int i=1;i<len;i++) a[i-1]=a[i]*(long long)i%mod;
        a[len-1]=0;
    }
    void poly_def(int *a,int len){
        int *inv=new int[len+2];inv[1]=1;
        for(int i=2;i<=len+1;i++) inv[i]=(mod-mod/i)*(long long)inv[mod%i]%mod;
        for(int i=len+1;i>=1;i--) a[i]=a[i-1]*(long long)inv[i]%mod;
        a[0]=0;delete []inv;
    }
    void poly_ln(int *a,int len){
        int *c=new int[len<<1];
        for(int i=0;i<len;i++) c[i]=a[i];
        for(int i=len;i<(len<<1);i++) c[i]=0;
        poly_inv(a,len);poly_der(c,len);
        poly_mul(a,c,len);poly_def(a,len);
        for(int i=len;i<(len<<1);i++) a[i]=0;
        delete []c;
    }
    void poly_cdq_FFT(int *a,int *b,int l,int r,void (*f)(int,int&)){
        if(l==r){f(l,a[l]);return;}
        int mid=(l+r)>>1,len;
        for(len=1;len<=(r-l);len<<=1);
        int *p=new int[len<<1],*q=new int[len<<1];
        poly_cdq_FFT(a,b,l,mid,f);
        for(int i=0;i<=mid-l;i++) p[i]=a[i+l];
        for(int i=mid-l+1;i<(len<<1);i++) p[i]=0;
        for(int i=0;i<=r-l-1;i++) q[i]=b[i+1];
        for(int i=r-l;i<(len<<1);i++) q[i]=0;
        poly_mul(p,q,len);
        for(int i=mid+1;i<=r;i++) a[i]=(a[i]+p[i-l-1])%mod;
        poly_cdq_FFT(a,b,mid+1,r,f);
        delete []p;delete []q;
    }
    void poly_exp(int *a,int len){
        if(len==1){a[0]=1;return;}
        int *b=new int[len<<1],*c=new int[len<<1];
        for(int i=0;i<(len>>1);i++) b[i]=a[i];
        for(int i=len>>1;i<(len<<1);i++) b[i]=0;
        poly_exp(b,len>>1);
        for(int i=0;i<(len>>1);i++) c[i]=b[i];
        for(int i=len>>1;i<(len<<1);i++) c[i]=0;
        poly_ln(c,len);
        a[0]++;
        for(int i=0;i<len;i++) a[i]=(a[i]-c[i]+mod)%mod;
        poly_mul(a,b,len);
        for(int i=len;i<(len<<1);i++) a[i]=0;
        delete []b;delete []c;
    }
    void poly_sqrt(int *a,int len){
        poly_ln(a,len);
        long long inv=fast_pow(2,mod-2);
        for(int i=0;i<len;i++) a[i]=a[i]*inv%mod;
        poly_exp(a,len);
    }
    void poly_fast_pow(int *a,int len,long long k){
        poly_ln(a,len);
        for(int i=0;i<len;i++) a[i]=a[i]*k%mod;
        poly_exp(a,len);
    }
    void poly_delivery(int *a,int n,int *b,int m,int *ra,int *rb){
        for(int i=0;i<=n;i++) ra[n-i]=a[i];
        for(int i=0;i<=m;i++) rb[m-i]=b[i];
        for(int i=n-m+1;i<=m;i++) rb[i]=0;
        int len;for(len=1;len<=n-m+1;len<<=1);poly_inv(rb,len);
        for(int i=n-m+1;i<len;i++) rb[i]=0;
        for(len=1;len<=n;len<<=1);poly_mul(ra,rb,len);
        reverse(ra,ra+n-m+1);
        for(int i=n-m+1;i<(len<<1);i++) ra[i]=0;
        for(int i=0;i<=m;i++) rb[i]=b[i];
        poly_mul(rb,ra,len);
        for(int i=m;i<(len<<1);i++) rb[i]=0;
        for(int i=0;i<m;i++) rb[i]=(a[i]-rb[i]+mod)%mod;
    }
}
using namespace Polynomial;
int n,m,g[1600010];
int main(){
    scanf("%d %d",&n,&m);init_W(m<<3);
    for(int i=1,x;i<=n;i++) scanf("%d",&x),g[x]=mod-4;
    int len;for(len=1;len<=m;len<<=1);
    g[0]=1;poly_sqrt(g,len);g[0]=pl(g[0],1);
    poly_inv(g,len);
    for(int i=1;i<=m;i++) printf("%d\n",2ll*g[i]%mod);
    return 0;
}