#include<bits/stdc++.h>
const int N=2e5+3,K=19;
int n,m,o[N],x[N],y[N],z[N],f[N],ans[N];
#define M (L+R>>1)
struct segment_tree1{
	int lz[1<<K];
	void Build(int L,int R,int k){
		lz[k]=m+1;
		if(L==R)return;
		Build(L,M,k<<1),Build(M+1,R,k<<1|1);
	}
	void Min(int l,int r,int a,int L,int R,int k){
		if(l<=L&&R<=r){lz[k]=std::min(lz[k],a);return;}
		if(l<=M)Min(l,r,a,L,M  ,k<<1  );
		if(r> M)Min(l,r,a,M+1,R,k<<1|1);
	}
	void Dfs(int mn,int L,int R,int k){
		mn=std::min(mn,lz[k]);
		if(L==R){ans[L]=mn,f[L]=mn==m+1?0:mn;return;}
		Dfs(mn,L,M,k<<1),Dfs(mn,M+1,R,k<<1|1);
	}
}t1;
struct data2{int mx,mn,mnp,mnc;};
inline data2 operator+(data2 a,data2 b){
	if(a.mn<b.mn){a.mx=std::max(a.mx,b.mx);return a;}
	if(a.mn>b.mn){b.mx=std::max(a.mx,b.mx);return b;}
	return(data2){std::max(a.mx,b.mx),a.mn,a.mnp,a.mnc+b.mnc};
}
struct segment_tree2{
	data2 s[1<<K];
	void Build(int L,int R,int k){
		if(L==R){s[k]=(data2){f[L],f[L],L,1};return;}
		Build(L,M,k<<1),Build(M+1,R,k<<1|1);
		s[k]=s[k<<1]+s[k<<1|1];
	}
	data2 Query(int l,int r,int L,int R,int k){
		if(l<=L&&R<=r)return s[k];
		if(r<=M)return Query(l,r,L,M  ,k<<1  );
		if(l> M)return Query(l,r,M+1,R,k<<1|1);
		return Query(l,r,L,M  ,k<<1  )+Query(l,r,M+1,R,k<<1|1);
	}
}t2;
signed main(){
	scanf("%d%d",&n,&m);
	t1.Build(1,n,1);
	for(int j=1;j<=m;j++){
		scanf("%d",o+j);
		if(o[j]==0){
			scanf("%d%d%d",x+j,y+j,z+j);
			if(!z[j])t1.Min(x[j],y[j],j,1,n,1);
		}
		else{
			scanf("%d",x+j);
		}
	}
	t1.Dfs(m+1,1,n,1);
	t2.Build(1,n,1);
	for(int j=1;j<=m;j++)
		if(z[j]){
			auto tmp=t2.Query(x[j],y[j],1,n,1);
			if(tmp.mnc==1)ans[tmp.mnp]=std::min(ans[tmp.mnp],std::max(j,tmp.mx));
		}
	for(int j=1;j<=m;j++)
		if(o[j]){
			puts(ans[x[j]]>j?"N/A":(!f[x[j]]?"YES":"NO"));
		}
	return 0;
}