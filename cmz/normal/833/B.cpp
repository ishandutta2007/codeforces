#include<bits/stdc++.h>
using namespace std;
const int maxn=35000+10;
int a[maxn];
struct seg{
	int x,tag;
}q[maxn*4];
int n,m,k;
int dp[55][maxn],cur[maxn*4];
int pre[maxn],last[maxn];
inline void pushup(int now){
	q[now].x=max(q[now*2].x,q[now*2+1].x);
}
inline void pushdown(int now){
	if (q[now].tag){
		int tmp=q[now].tag;
		q[now*2].x+=tmp; q[now*2+1].x+=tmp;
		q[now*2].tag+=tmp; q[now*2+1].tag+=tmp; 
		q[now].tag=0;
	}
}
void build(int now,int l,int r,int id){
	q[now].tag=0; 
	if (l==r){
		//if (id==2) printf("%d=%d\n",l,dp[id-1][l]);
		q[now].x=dp[id-1][l-1];	
		return;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid,id); build(now*2+1,mid+1,r,id);
	pushup(now);
}
int query(int now,int l,int r,int cl,int cr){
	if (r<cl||l>cr) return 0;
	if (l>=cl&&r<=cr) return q[now].x;
	pushdown(now);
	int mid=(l+r)/2;
	return max(query(now*2,l,mid,cl,cr),query(now*2+1,mid+1,r,cl,cr));
}
void change(int now,int l,int r,int cl,int cr,int k){
	if (r<cl||l>cr) return;
	if (l>=cl&&r<=cr){
		q[now].tag+=k; q[now].x+=k; return;
	}
	pushdown(now);
	int mid=(l+r)/2;
	change(now*2,l,mid,cl,cr,k); change(now*2+1,mid+1,r,cl,cr,k);
	pushup(now);
}
int main(){
	//freopen(".in","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		pre[i]=last[a[i]]; last[a[i]]=i;
	}
	for (int i=1;i<=k;++i){
		memset(q,0,sizeof(q));
		build(1,1,n,i);
		for (int j=1;j<=n;++j){
			change(1,1,n,pre[j]+1,j,1);
			dp[i][j]=query(1,1,n,1,j);
			//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}			
	}	
	printf("%d",dp[k][n]);
	return 0;
}