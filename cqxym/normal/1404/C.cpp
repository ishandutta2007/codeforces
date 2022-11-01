#include<stdio.h>
#include<algorithm>
#define R register int
#define I inline
#define N 300001
int a[N],f[N],ans[N];
class Fenwick{
	int c[N];
	public:
		I void Init(int&n){
			for(R i=1;i<=n;i++){
				c[i]=0;
			}
		}
		I void Add(int x,int d){
			if(x==0){
				c[0]+=d;
				return Add(1,d);
			}
			for(R i=x;i<N;i+=i&-i){
				c[i]+=d;
			}
		}
		I int GetSum(int x){
			int res=c[0];
			for(R i=x;i!=0;i&=i-1){
				res+=c[i];
			}
			return res;
		}
		I int Find(int x,int m,int k,int&n){
			if(k<=0){
				return x;
			}
			if(m==0){
				return x+1;
			}
			if(x+m>n){
				return Find(x,m>>1,k,n);
			}
			if(c[x+m]>=k){
				return Find(x,m>>1,k,n);
			}
			return Find(x+m,m>>1,k-c[x+m],n);
		}
}T;
struct Matrix{
	int X,Y,id;
	I friend bool operator<(Matrix A,Matrix B){
		if(A.Y!=B.Y){
			return A.Y<B.Y;
		}
		if(A.id!=B.id){
			return A.id<B.id;
		}
		return A.X<B.X;
	}
}p[1500000];
I void AddMatrix(int t,int lx,int ly,int rx,int ry){
	p[t<<2].id=p[t<<2|3].id=t<<1;
	p[t<<2|1].id=p[t<<2|2].id=t<<1|1;
	p[t<<2].X=p[t<<2|1].X=lx-1;
	p[t<<2|2].X=p[t<<2|3].X=rx;
	p[t<<2].Y=p[t<<2|2].Y=ly-1;
	p[t<<2|1].Y=p[t<<2|3].Y=ry;
}
int main(){
	int n,q,x,y;
	scanf("%d%d",&n,&q);
	int neg=0,zero=0;
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>i){
			f[i]=-1;
			neg++;
		}else{
			if(a[i]==i){
				f[i]=i-1;
			}else{
				if(a[i]<=neg){
					f[i]=-1;
					neg++;
				}else if(a[i]<=neg+zero){
					f[i]=0;
				}else{
					f[i]=T.Find(0,262144,a[i]-neg,n);
				}
			}
			if(f[i]==0){
				zero++;
			}
			if(f[i]!=-1){
				T.Add(f[i],1);
			}
		}
	}
	int s=(q<<2)+n;
	for(R i=0;i!=q;i++){
		scanf("%d%d",&x,&y);
		AddMatrix(i,x+1,x,n-y,n);
	}
	for(R i=1;i<=n;i++){
		int tem=i-1+(q<<2);
		p[tem].id=-1;
		p[tem].X=i;
		p[tem].Y=f[i];
	}
	std::sort(p,p+s);
	for(R i=0;i!=s;i++){
		if(p[i].id==-1){
			T.Add(p[i].X,1);
		}else{
			int tem=T.GetSum(p[i].X);
			if((p[i].id&1)==1){
				ans[p[i].id>>1]-=tem;
			}else{
				ans[p[i].id>>1]+=tem;
			}
		}
	}
	for(R i=0;i!=q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}