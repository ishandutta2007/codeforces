#include<bits/stdc++.h>
using namespace std;

int N;
int A[300005];
struct Node{
	int val,cnt;
	Node(){val=0x3f3f3f3f,cnt=1;}
	Node operator +(const Node b)const{
		Node c;c.val=min(val,b.val);
		c.cnt=(val==c.val?cnt:0)+(b.val==c.val?b.cnt:0);
		return c;
	}
}T[1200005];int Lzy[1200005];
void pushdown(int x){
	T[x<<1].val+=Lzy[x];Lzy[x<<1]+=Lzy[x];
	T[x<<1|1].val+=Lzy[x];Lzy[x<<1|1]+=Lzy[x];
	Lzy[x]=0;
}
void Update(int x,int l,int r,int L,int R,int K){
	if(L<=l&&r<=R){Lzy[x]+=K;T[x].val+=K;return;}
	int mid=(l+r)>>1;pushdown(x);
	if(L<=mid) Update(x<<1,l,mid,L,R,K);
	if(R>mid) Update(x<<1|1,mid+1,r,L,R,K);
	T[x]=T[x<<1]+T[x<<1|1];
}
Node Query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R) return T[x];
	int mid=(l+r)>>1;pushdown(x);
	if(R<=mid) return Query(x<<1,l,mid,L,R);
	if(L>mid) return Query(x<<1|1,mid+1,r,L,R);
	return Query(x<<1,l,mid,L,R)+Query(x<<1|1,mid+1,r,L,R);
}

int stk0[300005],len0;
int stk1[300005],len1;

long long ans;

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){int x,y;scanf("%d%d",&x,&y);A[x]=y;}
	for(int i=1;i<=N;i++){
		while(len0&&A[stk0[len0]]>A[i]) Update(1,1,N,stk0[len0-1]+1,stk0[len0],A[stk0[len0]]-A[i]),len0--;
		while(len1&&A[stk1[len1]]<A[i]) Update(1,1,N,stk1[len1-1]+1,stk1[len1],A[i]-A[stk1[len1]]),len1--;
		stk0[++len0]=i,stk1[++len1]=i;
		Update(1,1,N,i,i,-0x3f3f3f3f+i);
		ans+=T[1].cnt;
	}
	printf("%lld\n",ans);
}