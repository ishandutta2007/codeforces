#include<cstdio>
inline int min(int a,int b){return a<b?a:b;}
typedef long long ll;
const int K=30,N=1e5+2;
int n,a;
struct trie{
	int son[N*K][2],t;
	inline void Insert(int a){
		int k=0,f;
		for(int j=K-1;~j;j--){
		  f=(bool)(a&1<<j);
		  if(!son[k][f])son[k][f]=++t;
		  k=son[k][f];
		}
	}
	inline int Minxor(int a,int k,int d){
		int f,s=0;
		for(int j=d-1;~j;j--){
		  f=(bool)(a&1<<j);
		  if(!son[k][f])f^=1,s+=1<<j;
		  k=son[k][f];
		}return s;
	}
	inline int Dfs(int k,int a,int kk,int d){
		if(!son[k][0]&&!son[k][1])return Minxor(a,kk,d);
		int mn=1<<K;
		if(son[k][0])mn=min(mn,Dfs(son[k][0],a<<1,kk,d));
		if(son[k][1])mn=min(mn,Dfs(son[k][1],a<<1|1,kk,d));
		return mn;
	}
	inline ll Mst(int k,int d,int a){
	  ll s=0;
	  if(son[k][0])s+=Mst(son[k][0],d-1,a<<1);
	  if(son[k][1])s+=Mst(son[k][1],d-1,a<<1|1);
	  if(son[k][0]&&son[k][1])s+=Dfs(son[k][0],a<<1,son[k][1],d-1)+(1<<d-1);
	  return s;
	}
}t;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a),t.Insert(a);
	printf("%lld",t.Mst(0,K,0));
	return 0;
}