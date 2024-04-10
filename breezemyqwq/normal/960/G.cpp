#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define k1 b6e0_AK_IOI
#define k2 b6e1_AK_IOI
#define int long long
#define rg register
using namespace std;
const int maxl=100005<<4,mod=998244353,inv3=(mod+1)/3;

int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s*10+(ch^'0'))%mod;ch=getchar();}
	return s*w;
}
int n,k1,k2,ans;
int a[maxl],b1[maxl],b2[maxl],jc[maxl],inv[maxl];

int quick_power(int x,int y){
	int res=1;
	for (;y;y=y>>1,x=(x*x)%mod){
		if (y&1)  res=(res*x)%mod;
	}
	return res;
}
int ny(int tmpxtmpxxx){return quick_power(tmpxtmpxxx,mod-2);}

namespace poly{
	static int rev[maxl],tmp[maxl],F[maxl],G[maxl],B[maxl],C[maxl],D[maxl],R[maxl],ducati[maxl];
	static int inva[maxl],invb[maxl],dtmp[maxl],da[maxl],mul_num[maxl],f[maxl],g[maxl];
	
	void NTT(int *A,int len,int flag){
		for (rg int i=0;i<len;++i){
			if (i>rev[i])  swap(A[i],A[rev[i]]);
		}
		for (rg int i=2;i<=len;i*=2){
			int wn;
			if (flag==1)  wn=quick_power(3,(mod-1)/i);
			else wn=quick_power(inv3,(mod-1)/i);
			for (int j=0;j<len;j+=i){
				int w=1;
				for (rg int k=j;k<j+(i/2);k++){
					int u=A[k],v=(w*A[k+(i/2)])%mod;
					A[k]=(u+v)%mod,A[k+(i/2)]=(u+mod-v)%mod;
					w=(w*wn)%mod;
				}
			}
		}
		if (flag==-1){
			int ducati_cai=quick_power(len,mod-2);
			for (int i=0;i<len;++i)  A[i]=(A[i]*ducati_cai)%mod;
		}
	}
	void Mul(int *A,int *B,int *C,int n,int m){
		int p=1,cnt=0;
		while (p<=n+m)  p*=2,cnt++;
		for (int i=0;i<=p;++i)  rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
		for (int i=0;i<=n;++i)  F[i]=A[i];
		for (int i=0;i<=m;++i)  G[i]=B[i];
		for (int i=n+1;i<=p;++i)  F[i]=0;
		for (int i=m+1;i<=p;++i)  G[i]=0;
		
		NTT(F,p,1),NTT(G,p,1);
		for (rg int i=0;i<=p;++i)  C[i]=(F[i]*G[i])%mod;
		NTT(C,p,-1);
	}
	void get_inv(int *A,int *res,int len){
		if (len==1){
			res[0]=quick_power(A[0],mod-2);
			return;
		}
		get_inv(A,res,(len+1)>>1);
		
		int p=1,cnt=0;
		while (p<=2*len)  p*=2,cnt++;
		for (rg int i=0;i<=p;++i)  rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
		for (rg int i=0;i<=len;++i)  tmp[i]=A[i];
		for (int i=len;i<=p;++i)  tmp[i]=0;
		NTT(tmp,p,1),NTT(res,p,1);
		for (rg int i=0;i<=p;++i)  res[i]=(((2ll-res[i]*tmp[i])%mod+mod)%mod*res[i])%mod;
		NTT(res,p,-1);
		
		for (int i=len;i<=p;++i)  res[i]=0;
	}
	void Divide(int *A,int *B,int n,int m){
		reverse(B+1,B+m+1);
		reverse(A+1,A+n+1);
		get_inv(B,invb,n-m+1);
		Mul(A,invb,D,n-m,n-m);
		
		reverse(A+1,A+n+1);
		reverse(B+1,B+m+1);
		reverse(D+1,D+n-m+1);
		
		Mul(B,D,dtmp,m,n-m);
		for (rg int i=0;i<=n;++i)  R[i]=(A[i]-dtmp[i]+mod)%mod;
	}
	void qiudao(int *A,int *res,int len){
		for (rg int i=1;i<len;++i)  res[i-1]=(A[i]*i)%mod;
		res[len-1]=0;
	}
	void jifen(int *A,int *res,int len){
		for (int i=1;i<len;++i)  res[i]=(A[i-1]*ny(i))%mod;
		res[0]=0;
	}
	void get_ln(int *A,int *res,int len){
		memset(inva,0,sizeof(inva));
		
		get_inv(A,inva,len);
		qiudao(A,da,len);
		Mul(inva,da,mul_num,len,len);
		jifen(mul_num,res,len);
	}
	void get_exp(int *A,int *res,int len){
	    if (len==1){
	        res[0]=1;
	        return;
	    }
	    get_exp(A,res,(len+1)>>1);
	    
	    int p=1,cnt=0;
	    while (p<=len*2)  p*=2,cnt++;
	    for (rg int i=0;i<p;++i)  rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
	    for (rg int i=0;i<len;++i)  g[i]=A[i];
	    for (int i=len;i<p;++i)  g[i]=0;
	    for (int i=0;i<p;++i)  f[i]=0;
	    
	    get_ln(res,f,len);
	    NTT(g,p,1),NTT(f,p,1),NTT(res,p,1);
	    for (rg int i=0;i<p;++i)  res[i]=((1-f[i]+g[i]+mod)%mod*res[i])%mod;
	    NTT(res,p,-1);
	    
	    for (int i=len;i<p;++i)  res[i]=0;
	}
	void get_pow(int *A,int *res,int len,int k){
		memset(C,0,sizeof(C));
		get_ln(A,C,len);
		
		for (rg int i=0;i<len;++i)  C[i]=(C[i]*k)%mod;
		get_exp(C,res,len);
	}
	void ducati_get_pow(int *A,int *res,int len,int k){
		for (int i=1;i<=len;i++)  ducati[i-1]=A[i];
		poly::get_pow(ducati,res,len,k);
		
		for (int i=len-k;i>=0;i--)  res[i+k]=res[i];
		for (int i=0;i<k;i++)  res[i]=0;
	}
};

void init(){
	a[0]=0;
	for (int i=1;i<=n;i++)  a[i]=ny(i);
	
	jc[0]=1;
	for (int i=1;i<=n;i++)  jc[i]=(jc[i-1]*i)%mod;
	
	inv[n]=ny(jc[n]);
	for (int i=n-1;i>=0;i--)  inv[i]=(inv[i+1]*(i+1))%mod;
}

int C(int x,int y){
	if (x<0||y<0||x<y)  return 0;
	else return ((jc[x]*inv[y])%mod*inv[x-y])%mod;
}

void work1(int num){
	if (num==0){
		b1[0]=1;
		return;
	}
	poly::ducati_get_pow(a,b1,n+1,num);
	
	int val=inv[num];
	for (int i=0;i<=n;i++)  b1[i]=((b1[i]*jc[i])%mod*val)%mod;
}

void work2(int num){
	if (num==0){
		b2[0]=1;
		return;
	}
	poly::ducati_get_pow(a,b2,n+1,num);
	
	int val=inv[num];
	for (int i=0;i<=n;i++)  b2[i]=((b2[i]*jc[i])%mod*val)%mod;
}

signed main(){
	n=read(),k1=read()-1,k2=read()-1;init();
	work1(k1),work2(k2);
	
	for (int i=0;i<n;i++)  ans=(ans+((b1[i]*b2[n-1-i])%mod*C(n-1,i))%mod)%mod;
	cout<<ans<<endl;
	
	return 0;
}