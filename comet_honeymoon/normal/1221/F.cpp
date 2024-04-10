#include<bits/stdc++.h>
using namespace std;

const int maxN=500005;

int N;
int A1[maxN<<1],n;
struct node{
	int x,y,c;
	bool operator <(const node b)const{return x>b.x;}
}P[maxN];

long long ANS;
struct segtnode{
	long long Mval;int Mpos;
	segtnode operator +(const segtnode b)const{
		segtnode c;
		c.Mval=max(Mval,b.Mval);
		if(c.Mval==Mval) c.Mpos=Mpos;
		if(c.Mval==b.Mval) c.Mpos=b.Mpos;
		return c;
	}
}T[maxN<<3];
long long Lzy[maxN<<3];
void Add(int x,long long K){
	T[x].Mval+=K,Lzy[x]+=K;
}
void pushdown(int x){
	Add(x<<1,Lzy[x]);Add(x<<1|1,Lzy[x]);
	Lzy[x]=0;
}
void Build(int x,int l,int r){
	if(l==r){T[x].Mval=-A1[l],T[x].Mpos=l;return;}
	int mid=(l+r)>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	T[x]=T[x<<1]+T[x<<1|1];
}
void Update(int x,int l,int r,int L,int R,int K){
	if(L<=l&&r<=R){Add(x,K);return;}
	int mid=(l+r)>>1;pushdown(x);
	if(L<=mid) Update(x<<1,l,mid,L,R,K);
	if(R>mid) Update(x<<1|1,mid+1,r,L,R,K);
	T[x]=T[x<<1]+T[x<<1|1];
}
segtnode Query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R) return T[x];
	int mid=(l+r)>>1;pushdown(x);
	if(R<=mid) return Query(x<<1,l,mid,L,R);
	if(L>mid) return Query(x<<1|1,mid+1,r,L,R);
	return Query(x<<1,l,mid,L,R)+Query(x<<1|1,mid+1,r,L,R);
}

long long ansval=0,ansL=2000000000,ansR=2000000000;

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%d%d",&P[i].x,&P[i].y,&P[i].c);
		if(P[i].x>P[i].y) swap(P[i].x,P[i].y);
		A1[++n]=P[i].x,A1[++n]=P[i].y;
	}
	sort(A1+1,A1+n+1);n=unique(A1+1,A1+n+1)-A1-1;
	for(int i=1;i<=N;i++)
		P[i].x=lower_bound(A1+1,A1+n+1,P[i].x)-A1,
		P[i].y=lower_bound(A1+1,A1+n+1,P[i].y)-A1;
	Build(1,1,n);
	sort(P+1,P+N+1);
	for(int l=n,j=1;l;l--){
		while(j<=N&&P[j].x==l) Update(1,1,n,P[j].y,n,P[j].c),j++;
		segtnode tmp=Query(1,1,n,l,n);
		if(tmp.Mval+A1[l]>ansval) ansval=tmp.Mval+A1[l],ansL=A1[l],ansR=A1[tmp.Mpos];
	}
	printf("%lld\n%lld %lld %lld %lld\n",ansval,ansL,ansL,ansR,ansR);
}