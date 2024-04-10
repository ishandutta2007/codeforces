#include<bits/stdc++.h>
using namespace std;

int N;
int A[300005];
struct Node{
	int val,cnt;long long ans;
	Node(){val=0x3f3f3f3f,cnt=1;ans=0;}
	Node operator +(const Node b)const{
		Node c;c.val=min(val,b.val);
		c.cnt=(val==c.val?cnt:0)+(b.val==c.val?b.cnt:0);
		c.ans=ans+b.ans;
		return c;
	}
}T[1200005];int Lzy[1200005],Lzy2[1200005];
void pushdown(int x){
	T[x<<1].val+=Lzy[x];Lzy[x<<1]+=Lzy[x];
	T[x<<1|1].val+=Lzy[x];Lzy[x<<1|1]+=Lzy[x];
	Lzy[x]=0;
	if(T[x<<1].val==T[x].val) T[x<<1].ans+=1LL*T[x<<1].cnt*Lzy2[x],Lzy2[x<<1]+=Lzy2[x];
	if(T[x<<1|1].val==T[x].val) T[x<<1|1].ans+=1LL*T[x<<1|1].cnt*Lzy2[x],Lzy2[x<<1|1]+=Lzy2[x];
	Lzy2[x]=0;
}
void Update(int x,int l,int r,int L,int R,int K){
	if(L>R) return;
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

int Q;
vector<int> QL[300005],id[300005];
long long ANS[300005];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int L,R;scanf("%d%d",&L,&R);
		QL[R].push_back(L);id[R].push_back(i);
	}
	for(int i=1;i<=N;i++){
		Update(1,1,N,1,i-1,-1);
		while(len0&&A[stk0[len0]]>A[i]) Update(1,1,N,stk0[len0-1]+1,stk0[len0],A[stk0[len0]]-A[i]),len0--;
		while(len1&&A[stk1[len1]]<A[i]) Update(1,1,N,stk1[len1-1]+1,stk1[len1],A[i]-A[stk1[len1]]),len1--;
		stk0[++len0]=i,stk1[++len1]=i;
		Update(1,1,N,i,i,-0x3f3f3f3f);
		Lzy2[1]++;T[1].ans+=T[1].cnt;
		for(int j=0;j<QL[i].size();j++)
			ANS[id[i][j]]=Query(1,1,N,QL[i][j],i).ans;
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",ANS[i]);
}