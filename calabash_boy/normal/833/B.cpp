#include<bits/stdc++.h>
using namespace std;
const int MAXN=35050;
const int MAXK = 55;

struct Seg_Tree{
	int value[MAXN<<2],lazy[MAXN<<2];
	void clear(){
		memset(value,0,sizeof(value));
		memset(lazy,0,sizeof(lazy));
	}	
	void Down(int x){
		int lc = x<<1,rc = x<<1|1;
		value[lc]+=lazy[x];
		value[rc]+=lazy[x];
		lazy[lc]+=lazy[x];
		lazy[rc]+=lazy[x];
		lazy[x]= 0;
	}
	void Up(int x){
		value[x]=max(value[x<<1],value[x<<1|1]);
	}
	void Update(int x,int l,int r,int L,int R,int delta){
		if (l>R||r<L){
			return;
		}
		if (L<=l&&r<=R){
			value[x]+=delta;
			lazy[x]+=delta;
			return;
		}
		if (lazy[x]){
			Down(x);
		}
		int Mid = (l+r)>>1;
		Update(x<<1,l,Mid,L,R,delta);
		Update(x<<1|1,Mid+1,r,L,R,delta);
		Up(x); 
	}
	void Update1(int x,int l,int r,int index,int delta){
		if (l==r){
			value[x]+=delta;
			return;
		}
		if (lazy[x]){
			Down(x);
		}
		int Mid = (l+r)>>1;
		if (index<=Mid){
			Update1(x<<1,l,Mid,index,delta);
		}else{
			Update1(x<<1|1,Mid+1,r,index,delta);
		}
		Up(x);
	}
	int getMax(){
		return value[1];
	}
}tree;
int last[MAXN];
int pre[MAXN];
int dp[2][MAXN];
int n,k,x,b;
int main(){
	scanf("%d%d",&n,&k);
	for (int i = 1;i<=n;i++){
		scanf("%d",&x);
		pre[i] = last[x];
		last[x]= i;
	}
	for (int i = 1;i<=k;i++,b^=1){
		tree.clear();
		for (int j = 1;j<=n;j++){
			tree.Update(1,0,n,pre[j],j-1,1);
			tree.Update1(1,0,n,j-1,dp[b^1][j-1]);
			dp[b][j]= tree.getMax();
//			cout<<tree.getMax()<<endl; 
		}
	}
	printf("%d\n",dp[b^1][n]);
	return 0; 
}