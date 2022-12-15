#include<bits/stdc++.h>
using namespace std;

int N,K,Q;
int A[100005],mxA=0x3f3f3f3f;
int ST[100005][20];
int lg2[100005];
void get_ST(){
	lg2[0]=-1;for(int i=1;i<=N;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=N-1;~i;i--){
		ST[i][0]=A[i];
		for(int k=1;i+(1<<k)-1<N;k++)
			ST[i][k]=min(ST[i][k-1],ST[i+(1<<(k-1))][k-1]);
	}
}
int rmq(int l,int r){
	int k=lg2[r-l+1];
	return min(ST[l][k],ST[r-(1<<k)+1][k]);
}
int RMQ(int l,int r){
	if(l/N+1<=r/N-1) return mxA;
	if(l/N==r/N) return rmq(l%N,r%N);
	return min(rmq(l%N,N-1),rmq(0,r%N));
}

int val[100005],lenval;
int tag[10000005],sum[10000005],lc[10000005],rc[10000005],idx;
void pushdown(int x){
	if(!tag[x]) return;
	if(!lc[x]) lc[x]=++idx;tag[lc[x]]=tag[x],sum[lc[x]]=val[tag[x]];
	if(!rc[x]) rc[x]=++idx;tag[rc[x]]=tag[x],sum[rc[x]]=val[tag[x]];
	tag[x]=0; 
}
void Update(int &x,int l,int r,int L,int R,int W){
	if(!x) x=++idx,sum[x]=RMQ(l,r);
	if(L<=l&&r<=R){tag[x]=W;sum[x]=val[W];return;}
	int mid=(l+r)>>1;pushdown(x);
	if(L<=mid) Update(lc[x],l,mid,L,R,W);
	if(R>mid) Update(rc[x],mid+1,r,L,R,W);
	sum[x]=0x3f3f3f3f;
	if(lc[x]) sum[x]=min(sum[x],sum[lc[x]]);
	else sum[x]=min(sum[x],RMQ(l,mid));
	if(rc[x]) sum[x]=min(sum[x],sum[rc[x]]);
	else sum[x]=min(sum[x],RMQ(mid+1,r));
}
int Query(int x,int l,int r,int L,int R){
	if(!x) return RMQ(max(L,l),min(R,r));
	if(L<=l&&r<=R) return sum[x];
	int mid=(l+r)>>1,ans=0x3f3f3f3f;pushdown(x);
	if(L<=mid) ans=min(ans,Query(lc[x],l,mid,L,R));
	if(R>mid) ans=min(ans,Query(rc[x],mid+1,r,L,R));
	return ans;
}

int rt;

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%d",&A[i]),mxA=min(mxA,A[i]);
	get_ST();
	scanf("%d",&Q);
	while(Q--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int l,r,c;scanf("%d%d%d",&l,&r,&c);l--;r--;
			val[++lenval]=c;
			Update(rt,0,N*K-1,l,r,lenval);
		}
		else{
			int l,r;scanf("%d%d",&l,&r);l--;r--;
			printf("%d\n",Query(rt,0,N*K-1,l,r));
		}
	}
}