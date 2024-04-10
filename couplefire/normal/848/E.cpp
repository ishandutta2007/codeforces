#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> poly;

const int N=131072,mod=998244353,G=3,invG=332748118;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return 1LL*a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}
int Power(int a,int k,int p=mod){int res=1;for (;k;k>>=1,smul(a,a,p)) if (k&1) smul(res,a,p);return res;}
int Get_inv(int a,int p=mod){return Power(a,p-2,p);}

int wn[2][N+9];

void Get_wn(){
  int w0=Power(G,(mod-1)/N),w1=Power(invG,(mod-1)/N);
  wn[0][0]=wn[1][0]=1;
  for (int i=1;i<=N;++i){
	wn[0][i]=mul(wn[0][i-1],w0);
	wn[1][i]=mul(wn[1][i-1],w1);
  }
}

int len,rev[N+9];

void Get_len(int n){
  int l=0;
  for (len=1;len<n;len<<=1) ++l;
  for (int i=0;i<len;++i) rev[i]=rev[i>>1]>>1|(i&1)<<l-1;
}

void NTT(poly &a,int n,int t){
  static int pw[N+9];
  static ULL ntt[N+9];
  for (int i=0;i<n;++i) ntt[i]=a[rev[i]];
  for (int i=1;i<n;i<<=1){
	int tl=N/(i<<1);
	for (int j=0;j<i;++j) pw[j]=wn[t][j*tl];
	for (int j=0;j<n;j+=i<<1)
	  for (int k=0;k<i;++k){
		ULL x=ntt[j+k],y=pw[k]*ntt[i+j+k]%mod;
		ntt[j+k]=x+y;ntt[i+j+k]=x+mod-y;
	  }
	if (i==1<<15)
	  for (int j=0;j<n;++j) ntt[j]%=mod;
  }
  for (int i=0;i<n;++i) a[i]=ntt[i]%mod;
  if (!t) return;
  t=Get_inv(n);
  for (int i=0;i<n;++i) smul(a[i],t);
}

int n;

void into(){
  scanf("%d",&n);
}

poly f[2][2],g,h[2];

void Divide_h(int id,int l,int r){
  if (l==r){
	if (!l) h[id][l]=1;
	return;
  }
  int mid=l+r>>1;
  Divide_h(id,l,mid);
  Get_len(r-l+1);
  for (int u=0;u<2;++u){
	poly a=poly(h[u].begin()+l,h[u].begin()+mid+1);
	a.resize(len);
	NTT(a,len,0);
	for (int v=0;v<2;++v){
	  poly tmp=poly(f[u][v].begin(),f[u][v].begin()+r-l+1);
	  tmp.resize(len);
	  NTT(tmp,len,0);
	  for (int i=0;i<len;++i) smul(tmp[i],a[i]);
	  NTT(tmp,len,1);
	  for (int i=mid+1;i<=r;++i) sadd(h[v][i],tmp[i-l]);
	}
  }
  Divide_h(id,mid+1,r);
}

int ans;

void Get_ans(){
  g.resize(n+1);
  g[0]=g[2]=1;
  for (int i=4;i<=n;i+=2) g[i]=add(g[i-2],g[i-4]);
  for (int u=0;u<2;++u)
	for (int v=0;v<2;++v) f[u][v].resize(n+1);
  for (int i=1;i<=n;++i)
	for (int u=0;u<2;++u)
	  for (int v=0;v<2;++v) f[u][v][i]=i-u-v-1>=0?mul(g[i-u-v-1],mul(i-1,i-1)):0;
  for (int id=0;id<2;++id){
	h[0]=poly(n+1,0);
	h[1]=poly(n+1,0);
	Divide_h(id,0,n);
    for (int i=0;i<n;++i)
	  for (int u=0;u<2;++u) sadd(ans,mul(mul(h[u][i],f[u][id][n-i]),n-i));
  }
}

void work(){
  Get_wn();
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
	work();
    outo();
  }
  return 0;
}