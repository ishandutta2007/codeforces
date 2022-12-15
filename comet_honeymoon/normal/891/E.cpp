#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int p=1000000007,maxN=1<<18;
int fac[maxN],ifac[maxN],inv[maxN];
int qpow(int a,int k){
    int ans=1;
    while(k){
        if(k&1) ans=1LL*ans*a%p;
        a=1LL*a*a%p;
        k>>=1;
    }
    return ans;
}

const double Pi=acos(-1);
struct Cpl{
    double r,i;
    Cpl operator +(const Cpl b)const{return (Cpl){r+b.r,i+b.i};}
    Cpl operator -(const Cpl b)const{return (Cpl){r-b.r,i-b.i};}
    Cpl operator *(const Cpl b)const{return (Cpl){r*b.r-i*b.i,r*b.i+i*b.r};}
}W[maxN],iW[maxN];
 
int R[maxN];
void FFT(Cpl d[],int n0,bool flg){
    int x=1,len=0;while(x<n0) x<<=1,len++;
    for(int i=0;i<x;i++){
        R[i]=(R[i>>1]>>1)|((i&1)<<(len-1));
        if(i<R[i]) swap(d[i],d[R[i]]);
    }
    for(int i=1,l=maxN/(i<<1);i<x;i<<=1,l>>=1)
    for(int j=0;j<x;j+=(i<<1))
    for(int k=0;k<i;k++){
        Cpl a0=d[j+k],a1=(flg?iW[l*k]:W[l*k])*d[j+i+k];
        d[j+k]=a0+a1;d[j+i+k]=a0-a1;
    }
    if(flg){
        for(int i=0;i<x;i++) d[i].r/=x,d[i].i/=x;
    }
}
Cpl a1[maxN],b1[maxN],a0[maxN],b0[maxN],c1[maxN],c2[maxN],c3[maxN];
void Conv(int A[],int B[],int ans[],int n0,int p){
    int x=1;while(x<n0) x<<=1;
	for(int i=0;i<n0;i++) a1[i].r=A[i]>>15;
	for(int i=0;i<n0;i++) b1[i].r=B[i]>>15;
	for(int i=0;i<n0;i++) a0[i].r=A[i]&0x7fff;
	for(int i=0;i<n0;i++) b0[i].r=B[i]&0x7fff;
	FFT(a1,n0,0);FFT(b1,n0,0);FFT(a0,n0,0);FFT(b0,n0,0);
	for(int i=0;i<x;i++)
		c1[i]=a1[i]*b1[i],
		c2[i]=a1[i]*b0[i]+a0[i]*b1[i],
		c3[i]=a0[i]*b0[i];
	FFT(c1,n0,1);FFT(c2,n0,1);FFT(c3,n0,1);
	for(int i=0;i<n0;i++)
		ans[i]=(((ll)round(c1[i].r)%p<<30)%p+((ll)round(c2[i].r)%p<<15)%p+(ll)round(c3[i].r)%p)%p;
	for(int i=0;i<x;i++)
		a1[i].r=a1[i].i=0,b1[i].r=b1[i].i=0,a0[i].r=a0[i].i=0,b0[i].r=b0[i].i=0,c1[i].r=c1[i].i=0,c2[i].r=c2[i].i=0,c3[i].r=c3[i].i=0;
} 

int N,K;
int A[5005];
vector<int> F[20005];
int tmpa[maxN],tmpb[maxN],tmpc[maxN];
void Solve(int x,int l,int r){
	if(l==r){F[x].push_back(A[l]);F[x].push_back(p-1);return;}
	int mid=(l+r)>>1;
	Solve(x<<1,l,mid);Solve(x<<1|1,mid+1,r);
	int len=F[x<<1].size()+F[x<<1|1].size()-1;
	int n0=1;while(n0<len) n0<<=1;
	for(int i=0;i<n0;i++) tmpa[i]=tmpb[i]=tmpc[i]=0;
	for(int i=0;i<F[x<<1].size();i++) tmpa[i]=F[x<<1][i];F[x<<1].clear();
	for(int i=0;i<F[x<<1|1].size();i++) tmpb[i]=F[x<<1|1][i];F[x<<1|1].clear();
	Conv(tmpa,tmpb,tmpc,n0,p);
	for(int i=0;i<len;i++) F[x].push_back(tmpc[i]);
}

void init(){
	for(int i=0;i<maxN;i++)
        W[i]=(Cpl){cos(i*Pi/(maxN>>1)),sin(i*Pi/(maxN>>1))},
        iW[i]=(Cpl){cos(i*Pi/(maxN>>1)),-sin(i*Pi/(maxN>>1))};
    inv[1]=fac[1]=fac[0]=ifac[1]=ifac[0]=1;
    for(int i=2;i<maxN;i++)
    	inv[i]=1LL*(p-p/i)*inv[p%i]%p,
    	fac[i]=1LL*fac[i-1]*i%p,
    	ifac[i]=1LL*ifac[i-1]*inv[i]%p;
}

int main(){
	init();
	scanf("%d%d",&N,&K);
	int SA=1;
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),SA=1LL*SA*A[i]%p;
	Solve(1,1,N);
	int ans=0,powN=qpow(N,K),invN=qpow(N,p-2),mul=1;
	for(int i=0;i<=K&&i<F[1].size();i++,powN=1LL*powN*invN%p,mul=1LL*mul*(K-i+1)%p)
		ans=(ans+1LL*F[1][i]*mul%p*powN%p)%p;
	
	printf("%d\n",(SA-1LL*ans*qpow(qpow(N,K),p-2)%p+p)%p);
}