#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
typedef unsigned uint;
#define G getchar()
inline uint read()
{
	uint x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int K,q,n;
struct Rec{
	uint l,r,v;
}rec[200010];
uint A[1<<16|10],B[1<<16|10];

int M[1<<16|10],N[1<<16|10];
void ins(int *tag,int l,int r){tag[l]++,tag[r+1]--;}
int P[1<<16|10],Q[1<<16|10];
int ask(int *P,int l,int r){
	int res=P[r]; if (l) res-=P[l-1];
	return res;
}

bool work(int pos){
	for (int i=0;i<=n;i++) M[i]=N[i]=P[i]=Q[i]=0;
	for (int i=1;i<=q;i++){
		int la=rec[i].l>>K,ra=rec[i].r>>K,lb=rec[i].l&((1<<K)-1),rb=rec[i].r&((1<<K)-1);
		if (rec[i].v>>pos&1){
			ins(M,la,ra);
			if (la==ra) ins(N,lb,rb);
			else{
				if (la+1<ra) ins(N,0,n-1);
				else ins(N,lb,n-1),ins(N,0,rb);
			}
		}
	}
	for (int i=0;i<n;i++){
		if (i) M[i]+=M[i-1],N[i]+=N[i-1],P[i]=P[i-1],Q[i]=Q[i-1];
		P[i]+=M[i]!=0; Q[i]+=N[i]!=0;
	}
	for (int i=1;i<=q;i++){
		int la=rec[i].l>>K,ra=rec[i].r>>K,lb=rec[i].l&((1<<K)-1),rb=rec[i].r&((1<<K)-1);
		if (rec[i].v>>pos&1);
		else{
			if (la==ra){
				if (ask(P,la,ra)&&ask(Q,lb,rb)) return 0;
			}
			else{
				if (ask(P,la,la)&&ask(Q,lb,n-1)) return 0;
				if (ask(P,ra,ra)&&ask(Q,0,rb)) return 0;
				if (la+1<ra&&ask(P,la+1,ra-1)&&ask(Q,0,n-1)) return 0;
			}
		}
	}
	for (int i=0;i<n;i++){
		if (M[i]) A[i]|=1<<pos;
		if (N[i]) B[i]|=1<<pos;
	}
	return 1;
}

int main()
{
	K=read(),q=read(),n=1<<K;
	for (int i=1;i<=q;i++) rec[i].l=read(),rec[i].r=read(),rec[i].v=read();
	for (int i=0;i<16;i++) if (!work(i)) return puts("impossible"),0;
	puts("possible");
	for (int i=0;i<n;i++) printf("%u\n",B[i]);
	for (int i=0;i<n;i++) printf("%u\n",A[i]);
	return 0;
}