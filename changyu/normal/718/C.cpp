#include<bits/stdc++.h>
typedef long long ll;
const int N=100003,D=1<<18,K=50,M=1e9+7;
struct matrix{int a[2][2];};
matrix one,pw[K];
inline void Plus(matrix&c,matrix a,matrix b){c=(matrix){(a.a[0][0]+b.a[0][0])%M,(a.a[0][1]+b.a[0][1])%M,(a.a[1][0]+b.a[1][0])%M,(a.a[1][1]+b.a[1][1])%M};}
inline void Mult(matrix&c,matrix a,matrix b){c=(matrix){(int)(((ll)a.a[0][0]*b.a[0][0]+(ll)a.a[0][1]*b.a[1][0])%M),(int)(((ll)a.a[0][0]*b.a[0][1]+(ll)a.a[0][1]*b.a[1][1])%M),(int)(((ll)a.a[1][0]*b.a[0][0]+(ll)a.a[1][1]*b.a[1][0])%M),(int)(((ll)a.a[1][0]*b.a[0][1]+(ll)a.a[1][1]*b.a[1][1])%M)};}
inline void Pow(matrix&c,matrix a,ll m){c=one;for(int j=0;j<K;j++)if(m>>j&1)Mult(c,c,pw[j]);}
int n,m,a[N];
#define Md (L+R>>1)
struct segment_tree{
	matrix s[D],tmp;ll lz[D];
	void Build(int L,int R,int k){
		if(L==R){Pow(s[k],pw[0],a[L]);return;}
		Build(L,Md,k<<1),Build(Md+1,R,k<<1|1);
		Plus(s[k],s[k<<1],s[k<<1|1]);
	}
	inline void Go(ll x,int k){Pow(tmp,pw[0],x),Mult(s[k],s[k],tmp);}
	inline void Down(int k){
		if(!lz[k])return;
		lz[k<<1  ]+=lz[k],Go(lz[k],k<<1  );
		lz[k<<1|1]+=lz[k],Go(lz[k],k<<1|1);
		lz[k]=0;
	}
	void Add(int l,int r,int x,int L,int R,int k){
		if(l<=L&&R<=r){lz[k]+=x,Go(x,k);return;}
		Down(k);
		if(l<=Md)Add(l,r,x,L  ,Md,k<<1  );
		if(r> Md)Add(l,r,x,Md+1,R,k<<1|1);
		Plus(s[k],s[k<<1],s[k<<1|1]);
	}
	int Query(int l,int r,int L,int R,int k){
		if(l<=L&&R<=r)return s[k].a[0][1];
		Down(k);
		if(r<=Md)return Query(l,r,L  ,Md,k<<1  );
		if(l> Md)return Query(l,r,Md+1,R,k<<1|1);
		return(Query(l,r,L,Md,k<<1)+Query(l,r,Md+1,R,k<<1|1))%M;
	}
}t;
int main(){
	int o,x,y,z;
	one=(matrix){1,0,0,1};
	pw[0]=(matrix){0,1,1,1};
	for(int j=1;j<K;j++)Mult(pw[j],pw[j-1],pw[j-1]);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	t.Build(1,n,1);
	for(;m--;){
	  scanf("%d%d%d",&o,&x,&y);
	  if(o==1)scanf("%d",&z),t.Add(x,y,z,1,n,1);
	  else printf("%d\n",t.Query(x,y,1,n,1));
	}return 0;
}