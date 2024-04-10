#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3,D=1<<17,M=998244353,INV100=828542813;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int n,x[N],v[N],p[N],cnt,ans;
struct boom{int p,f,a,b;}opt[N*2];
bool Cmp(const boom&a,const boom&b){return(ll)a.a*b.b<(ll)b.a*a.b;}
struct matrix{
	int a[2][2];
	inline matrix operator*(matrix b){
		matrix c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				c.a[i][j]=0;
				for(int k=0;k<2;k++)
					c.a[i][j]=(c.a[i][j]+(ll)a[i][k]*b.a[k][j])%M;
			}
		return c;
	}
}one=(matrix){1,0,0,1};
struct segment_tree{
	matrix s[D+D];
	void Init(){
		for(int k=1;k<D+D;k++)s[k]=one;
		for(int i=1;i<=n;i++)s[i+D]=(matrix){p[i],p[i],(M+1-p[i])%M,(M+1-p[i])%M};
		for(int k=D-1;k;k--)s[k]=s[k<<1|1]*s[k<<1];
	}
	inline void Update(int k,matrix a){
		for(s[k+=D]=a,k>>=1;k;k>>=1)s[k]=s[k<<1|1]*s[k<<1];
	}
	inline matrix Ans(){return s[1];}
	inline matrix Query(int k){return s[k+D];}
}t;
int main(){
	matrix tmp0,tmp1,tmp2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",x+i,v+i,p+i),p[i]=(ll)p[i]*INV100%M;
	t.Init();
	for(int i=1;i<n;i++){
		opt[++cnt]=(boom){i,2,x[i+1]-x[i],v[i]+v[i+1]};
		if(v[i]>v[i+1])
			opt[++cnt]=(boom){i,0,x[i+1]-x[i],v[i]-v[i+1]};
		if(v[i]<v[i+1])
			opt[++cnt]=(boom){i,3,x[i+1]-x[i],v[i+1]-v[i]};
	}
	std::sort(opt+1,opt+1+cnt,Cmp);
	for(int j=1;j<=cnt;j++){
		tmp1=tmp0=t.Query(opt[j].p+1);
		for(int x=0;x<2;x++)
			for(int y=0;y<2;y++)
				if(x!=(opt[j].f>>1)||y!=(opt[j].f&1))tmp1.a[x][y]=0;
		t.Update(opt[j].p+1,tmp1);
		tmp2=t.Ans();
		ans=(ans+(ll)(tmp2.a[0][0]+tmp2.a[1][0])*opt[j].a%M*Pow(opt[j].b,M-2))%M;
		tmp0.a[opt[j].f>>1][opt[j].f&1]=0;
		t.Update(opt[j].p+1,tmp0);
	}
	printf("%d\n",ans);
	return 0;
}