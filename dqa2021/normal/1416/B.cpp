#include<cstdio>
#include<algorithm>
#include<cctype>
#include<assert.h>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,w[10010];
struct Rec{
	int i,j,x;
}rec[30010]; int rectop;
void init(){
}
void solve(){
	n=read();
	int S=0;
	for (int i=1;i<=n;i++) w[i]=read(),S+=w[i];
	if (S%n) return puts("-1"),void();
	S/=n;
	rectop=0;
	for (int i=2;i<=n;i++){
		int t=(w[i]+i-1)/i;
		t=t*i-w[i];
		assert(w[1]>=t);
		rec[++rectop]=(Rec){1,i,t};
		w[1]-=t; w[i]+=t;
		t=w[i]/i;
		rec[++rectop]=(Rec){i,1,t};
		w[i]-=t*i; w[1]+=t*i;
	}
	for (int i=2;i<=n;i++) rec[++rectop]=(Rec){1,i,S},w[1]-=S,w[i]+=S;
	for (int i=1;i<=n;i++) assert(w[i]==S);
	assert(rectop<=3*n);
	printf("%d\n",rectop);
	for (int i=1;i<=rectop;i++) printf("%d %d %d\n",rec[i].i,rec[i].j,rec[i].x);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}