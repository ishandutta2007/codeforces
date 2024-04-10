#include<cstdio>
#include<algorithm>
#include<cstring>
const int N=2e5+8;
#define M (L+R>>1)
struct segment_tree{
	int x[1<<19];
	segment_tree(){memset(x,-1,sizeof x);}
	inline void Down(int k){
		x[k<<1]=std::max(x[k],x[k<<1]);
		x[k<<1|1]=std::max(x[k],x[k<<1|1]);
		x[k]=-1;
	}
	void Update(int p,int a,int L,int R,int k){
		if(L==R){x[k]=a;return;}
		Down(k);
		p<=M?Update(p,a,L,M,k<<1):Update(p,a,M+1,R,k<<1|1);
	}
	inline void Max(int a){x[1]=std::max(x[1],a);}
	void Dfs(int L,int R,int k){
		if(L==R){printf("%d ",x[k]);return;}
		Down(k);
		Dfs(L,M,k<<1);Dfs(M+1,R,k<<1|1);
	}
}t;
int n,m;
int main(){
	int o,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&x),t.Update(i,x,1,n,1);
	scanf("%d",&m);
	for(;m--;){
	  scanf("%d%d",&o,&x);
	  if(o==1)scanf("%d",&y),t.Update(x,y,1,n,1);
	  else t.Max(x);
	}t.Dfs(1,n,1);
	return 0;
}