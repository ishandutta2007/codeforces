#include<bits/stdc++.h>
using namespace std;
int L[18][200004],R[18][200004];
int n,N,lg[200004];
int l[200004],r[200004];
int res[200004],ans[100004];
struct rng_mn{
	int st[18][200004];
	void init(int *a){
		for(int i=1;i<=N;i++)st[0][i]=a[i];
		for(int t=1;t<=lg[N];t++)
			for(int i=1,j=(1<<(t-1))+1,k=1<<t;k<=N;i++,j++,k++)
				st[t][i]=min(st[t-1][i],st[t-1][j]);
	}
	int qry(int l,int r){
		int d=lg[r-l];
		return min(st[d][l],st[d][r-(1<<d)+1]);
	}
}rmq0;
struct rmq_mx{
	int st[18][200004];
	void init(int *a){
		for(int i=1;i<=N;i++)st[0][i]=a[i];
		for(int t=1;t<=lg[N];t++)
			for(int i=1,j=(1<<(t-1))+1,k=1<<t;k<=N;i++,j++,k++)
				st[t][i]=max(st[t-1][i],st[t-1][j]);
	}
	int qry(int l,int r){
		int d=lg[r-l];
		return max(st[d][l],st[d][r-(1<<d)+1]);
	}
}rmq1;
int main(){
	scanf("%d",&n),N=n+n;if(n==1)return puts("0"),0;
	for(int i=2;i<=N;i++)lg[i]=lg[i>>1]+1;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x),ans[i]=n;
		L[0][i]=max(i-x,1),L[0][n+i]=n+i-x;
		R[0][i]=i+x,R[0][n+i]=min(n+i+x,n+n);
	}
	for(int t=1;t<18;t++){
		rmq0.init(L[t-1]),rmq1.init(R[t-1]);
		for(int i=1;i<=N;i++){
			L[t][i]=rmq0.qry(L[t-1][i],R[t-1][i]);
			R[t][i]=rmq1.qry(L[t-1][i],R[t-1][i]);
		}
	}
	for(int i=1;i<=N;i++)l[i]=r[i]=i;
	for(int t=17;~t;t--){
		rmq0.init(L[t]),rmq1.init(R[t]);
		for(int i=1;i<=N;i++){
			int L=rmq0.qry(l[i],r[i]);
			int R=rmq1.qry(l[i],r[i]);
			if(R-L+1<n)l[i]=L,r[i]=R,res[i]|=(1<<t);
		}
	}
	for(int i=1;i<=N;i++){
		int id=i>n?i-n:i;
		ans[id]=min(ans[id],res[i]+1);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}