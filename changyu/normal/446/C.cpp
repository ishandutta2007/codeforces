#include<cstdio>
typedef long long ll;
const int N=300003,K=20,M=1e9+9;
#define Md (L+R>>1)
int n,m,f[N];
inline int S(int a,int b,int n){return((ll)f[n]*a+(ll)f[n+1]*b-b+M)%M;}
inline int F(int a,int b,int n){return n?((ll)f[n-1]*a+(ll)f[n]*b)%M:a;}
struct segment_tree{
	int lz0[1<<K],lz1[1<<K],s[1<<K];
	inline void Down(int L,int R,int k){
		int a,b;
		a=lz0[k],b=lz1[k];
		lz0[k<<1]=(lz0[k<<1]+a)%M,lz1[k<<1]=(lz1[k<<1]+b)%M;
		s[k<<1]=(s[k<<1]+S(a,b,Md-L+1))%M;
		a=F(lz0[k],lz1[k],Md-L+1),b=F(lz0[k],lz1[k],Md-L+2);
		lz0[k<<1|1]=(lz0[k<<1|1]+a)%M,lz1[k<<1|1]=(lz1[k<<1|1]+b)%M;
		s[k<<1|1]=(s[k<<1|1]+S(a,b,R-Md))%M;
		lz0[k]=lz1[k]=0;
	}
	void Add(int l,int r,int L,int R,int k){
		if(l<=L&&R<=r){
		  int a=L-l+1;
		  lz0[k]=(lz0[k]+f[a])%M,lz1[k]=(lz1[k]+f[a+1])%M;
		  s[k]=(s[k]+S(f[a],f[a+1],R-L+1))%M;
		  return;
		}
		Down(L,R,k);
		if(l<=Md)Add(l,r,L,Md,k<<1);
		if(r> Md)Add(l,r,Md+1,R,k<<1|1);
		s[k]=(s[k<<1]+s[k<<1|1])%M;
	}
	int Sum(int l,int r,int L,int R,int k){
		if(l<=L&&R<=r)return s[k];
		Down(L,R,k);
		if(r<=Md)return Sum(l,r,L,Md,k<<1);
		if(l> Md)return Sum(l,r,Md+1,R,k<<1|1);
		return(Sum(l,r,L,Md,k<<1)+Sum(l,r,Md+1,R,k<<1|1))%M;
	}
	void Build(int L,int R,int k){
		if(L==R){scanf("%d",&s[k]);return;}
		Build(L,Md,k<<1),Build(Md+1,R,k<<1|1);
		s[k]=(s[k<<1]+s[k<<1|1])%M;
	}
}t;
int main(){
	int o,l,r;
	scanf("%d%d",&n,&m);
	f[1]=f[2]=1;
	for(int i=3;i<=n+2;i++)f[i]=(f[i-1]+f[i-2])%M;
	t.Build(1,n,1);
	for(;m--;){
	  scanf("%d%d%d",&o,&l,&r);
	  if(o==1)t.Add(l,r,1,n,1);
	  else printf("%d\n",t.Sum(l,r,1,n,1));
	}return 0;
}