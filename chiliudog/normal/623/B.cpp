#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=1000005;
typedef unsigned int ul;
typedef long long ll;
typedef unsigned long long ull;
namespace fastRead{
 inline char getc(){
  static char buf[8000000];static int cur=0,q=0;
  if(cur==q)
   cur=fread(buf,1,8000000,stdin),q=0;
  return cur==q?-1:buf[q++];
 }
 inline void rdu(ul& a){
  a=0; char p=getc();
  while(p>'9' || p<'0') p=getc();
  while(p<='9'&&p>='0') a=a*10+p-'0',p=getc();
 }
 inline void rdu(int& a){
  a=0; char p=getc();
  while(p>'9' || p<'0') p=getc();
  while(p<='9'&&p>='0') a=a*10+p-'0',p=getc();
 }
 inline void rdi(ll& a){
  a=0; ll sig=1; char p=getc();
  while((p>'9' || p<'0') && p!='-') p=getc();
  if(p=='-') sig=-1,p=getc();
  while(p<='9'&&p>='0') a=a*10+p-'0',p=getc();
  a*=sig;
 }
 inline void rdi(int& a){
  a=0; int sig=1; char p=getc();
  while((p>'9' || p<'0') && p!='-') p=getc();
  if(p=='-') sig=-1,p=getc();
  while(p<='9'&&p>='0') a=a*10+p-'0',p=getc();
  a*=sig;
 }
 inline void rdu(ull& a){
  a=0; char p=getc();
  while(p>'9' || p<'0') p=getc();
  while(p<='9'&&p>='0') a=a*10+p-'0',p=getc();
 }
 inline void putc(char p,bool e=0){
  static char buf[8000000 +10];static int q=0;
  if(~p) buf[q++]=p;
  if(e&&q || 8000000==q) fwrite(buf,q,1,stdout),q=0;
 }
 inline void pru(ul a){
  if(a>=10) pru(a/10); putc(a%10+'0');
 }
 inline void pru(int a){
  if(a>=10) pru(a/10); putc(a%10+'0');
 }
 inline void pri(int a){
  if(a<0) putc('-'),pru(-a); else pru(a);
 }
 inline void pru(ull a){
  if(a>=10) pru(a/10); putc(a%10+'0');
 }
 inline void pru(ll a){
  if(a>=10) pru(a/10); putc(a%10+'0');
 }
 inline void pri(ll a){
  if(a<0) putc('-'),pru(-a); else pru(a);
 }
 inline char nxtch(){
  char p=getc();
  while(~p && (p==' '||p=='\r'||p=='\n'||p=='\t'))p=getc();
  return p;
 }
} using namespace fastRead;
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long int64;
namespace mathfunctions{
	const int S=10;
	#define F(x) ((mul(x,x,n)+c)%(n))
	inline int64 gcd(int64 x,int64 y){
		return y==0?x:gcd(y,x%y);
	}
	inline int64 mul(int64 x,int64 y,int64 p){
		x%=p;y%=p;
		if (p<=1000000000)return x*y%p;
		if (p<=1000000000000ll)return (((x*(y>>20)%p)<<20)+x*(y&((1<<20)-1)))%p;
		int64 d=(int64)floor(x*(long double)y/p+0.5);
		int64 res=(x*y-d*p)%p;if (res<0)res+=p;
		return res;
	}
	inline int64 powmod(int64 a,int64 b,int64 mod){
		int64 res=1;for(;b;b>>=1){if(b&1)res=mul(res,a,mod);a=mul(a,a,mod);}
		return res;
	}
	inline bool check(int64 a,int64 x,int64 n,int64 times){
		int64 tmp=powmod(a,x,n);int64 last=tmp;
		fortodo(_,1,times){
			tmp=mul(tmp,tmp,n);if (tmp==1&&last!=1&&last!=n-1)return 1;last=tmp;
		}
		if (tmp!=1)return 1;return 0;
	}
	inline bool Miller(int64 n){
		if(n==1)return 1;if (n==2)return 1;if (n==3)return 1;if (n==5)return 1;
		if (!(n&1))return 0;if (n%3==0)return 0;if (n%5==0)return 0;
		int64 x=n-1,times=0;
		while(!(x&1))times++,x>>=1;
		fortodo(_,1,S){
			if (check(rand()%(n-2)+2,x,n,times))return 0;
		}
		return 1;
	}
	inline int64 rho(int64 n,int64 c){
		int64 x=rand()%n,y=F(x),t;
		while(x^y){
			t=gcd(n,abs(x-y));
			if (t>1ll&&t<n)return t;
			x=F(x);y=F(y);y=F(y);
		}
		return n;
	}
}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[maxn],n,va,vb;
int64 f[maxn][3];
const int64 inf=1ll<<60;
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
inline int64 check(int d){
	if(d==1)return inf;
	rep(i,1,n){
		if(a[i]%d==0){
			f[i][0]=f[i-1][0];
			f[i][1]=min(f[i-1][1],f[i-1][0])+va;
			f[i][2]=min(f[i-1][1],f[i-1][2]);
		}
		else if(((a[i]+1)%d==0)||((a[i]-1)%d==0)){
			f[i][0]=f[i-1][0]+vb;
			f[i][1]=min(f[i-1][1],f[i-1][0])+va;
			f[i][2]=min(f[i-1][2],f[i-1][1])+vb;
		}else{
			f[i][0]=f[i][2]=inf;
			f[i][1]=min(f[i-1][1],f[i-1][0])+va;
		}
	}
	return min(f[n][0],min(f[n][1],f[n][2]));
}
inline bool is_prime(int v){
	return mathfunctions::Miller(v);
}
int main(){
	rdu(n);rdu(va);rdu(vb);rep(i,1,n)rdu(a[i]);
	int tmp=sqrt(a[1]);int64 ans=inf;
	tmp=sqrt(a[1]);
	rep(i,1,tmp){
		if(a[1]%i!=0)continue;
		if(is_prime(i))ans=min(ans,check(i));
		if(is_prime(a[1]/i))ans=min(ans,check(a[1]/i));
	}
	a[1]--;
	tmp=sqrt(a[1]);
	rep(i,1,tmp){
		if(a[1]%i!=0)continue;
		if(is_prime(i))ans=min(ans,check(i)+vb);
		if(is_prime(a[1]/i))ans=min(ans,check(a[1]/i)+vb);
	}
	a[1]+=2;
	tmp=sqrt(a[1]);
	rep(i,1,tmp){
		if(a[1]%i!=0)continue;
		if(is_prime(i))ans=min(ans,check(i)+vb);
		if(is_prime(a[1]/i))ans=min(ans,check(a[1]/i)+vb);
	}
	a[1]--;
	tmp=sqrt(a[n]);
	rep(i,1,tmp){
		if(a[n]%i!=0)continue;
		if(is_prime(i))ans=min(ans,check(i));
		if(is_prime(a[n]/i))ans=min(ans,check(a[n]/i));
	}
	a[n]--;
	tmp=sqrt(a[n]);
	rep(i,1,tmp){
		if(a[n]%i!=0)continue;
		if(is_prime(i))ans=min(ans,check(i)+vb);
		if(is_prime(a[n]/i))ans=min(ans,check(a[n]/i)+vb);
	}
	a[n]+=2;
	tmp=sqrt(a[n]);
	rep(i,1,tmp){
		if(a[n]%i!=0)continue;
		if(is_prime(i))ans=min(ans,check(i)+vb);
		if(is_prime(a[n]/i))ans=min(ans,check(a[n]/i)+vb);
	}
	ans=min(ans,1ll*(n-1)*va);cout<<ans<<endl;
    return 0;
}