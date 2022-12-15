#include<bits/stdc++.h>
using namespace std;

int brand(){return (rand()<<15)+rand();}

int N,Q;
struct node{
	int c,p;
	bool operator <(const node b)const{return p>b.p||(p==b.p&&c<b.c);}
}A[200005];
int C[200005];

struct fhqtreap{
	int l,r,s,v,ans,lzy,lzy2;
	fhqtreap(){l=r=s=v=0;ans=lzy=lzy2=0;}
}T[200005];
void pushup(int x){T[x].s=T[T[x].l].s+T[T[x].r].s+1;}
void pushdown(int x){
	if(T[x].l) T[T[x].l].ans+=T[x].lzy,T[T[x].l].lzy+=T[x].lzy;
	if(T[x].r) T[T[x].r].ans+=T[x].lzy,T[T[x].r].lzy+=T[x].lzy;
	T[x].lzy=0;
	if(T[x].l) T[T[x].l].v+=T[x].lzy2,T[T[x].l].lzy2+=T[x].lzy2;
	if(T[x].r) T[T[x].r].v+=T[x].lzy2,T[T[x].r].lzy2+=T[x].lzy2;
	T[x].lzy2=0;
}
void Merge(int x,int y,int &M){
	if(!x||!y){M=x+y;return;}
	if(brand()%(T[x].s+T[y].s)<T[x].s) pushdown(x),M=x,Merge(T[x].r,y,T[M].r);
	else pushdown(y),M=y,Merge(x,T[y].l,T[M].l);
	pushup(M);
}
void Split(int x,int &L,int &R,int K){
	if(!x){L=R=0;return;}
	pushdown(x);
	if(T[x].v<=K) L=x,Split(T[x].r,T[L].r,R,K),pushup(L);
	else R=x,Split(T[x].l,L,T[R].l,K),pushup(R);
}
int stk[200005],len;
void Destroy(int x){
	stk[++len]=x;
	pushdown(x);
	if(T[x].l) Destroy(T[x].l);
	if(T[x].r) Destroy(T[x].r);
	T[x].l=0;T[x].r=0;T[x].s=1;
}
void debug(int x){
	pushdown(x);
	if(T[x].l) debug(T[x].l);
	printf("%d %d %d %d\n",x,T[x].l,T[x].r,T[x].v,T[x].ans);
	if(T[x].r) debug(T[x].r);
}

int rt;

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d%d",&A[i].c,&A[i].p);
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++) C[i]=A[i].c;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		T[i].s=1;scanf("%d",&T[i].v);
		int x,y;Split(rt,x,y,T[i].v);
		Merge(x,i,x);Merge(x,y,rt);
	}
	for(int i=1;i<=N;i++){
//		printf("check %d\n",C[i]);
		int x,y,z;Split(rt,x,y,C[i]-1);T[y].lzy++;T[y].ans++;Split(y,y,z,2*(C[i]-1));T[z].lzy2-=C[i],T[z].v-=C[i];
		Destroy(y);
		while(len){
			int u=stk[len];T[u].v-=C[i];
			int xx,yy;Split(x,xx,yy,T[u].v);
			Merge(xx,u,xx);Merge(xx,yy,x);
			len--;
		}
		Merge(x,z,rt);
//		debug(rt);
	}
	Destroy(rt);
	for(int i=1;i<=Q;i++) printf("%d ",T[i].ans);
}