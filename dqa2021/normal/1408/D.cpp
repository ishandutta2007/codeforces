#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
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

int n,m;
struct A{
	int x,y;
}a[2010];
bool operator<(const A &x,const A &y){
	return x.x<y.x||x.x==y.x&&x.y<y.y;
}
struct B{
	int x,y;
}b[2010];
int stk[2010],stktop;

struct Rec{
	int t,u,v;
}rec[2010*2010]; int rectop;
bool operator<(const Rec &x,const Rec &y){
	return x.t<y.t;
}

priority_queue<int> P,Q;  //ins del

int c[2010];
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		b[i]=(B){x,y};
	}
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		a[i]=(A){x,y};
	}
	sort(a+1,a+m+1);
	for (int i=1;i<=m;i++){
		while (stktop&&a[i].y>=a[stk[stktop]].y) stktop--;
		stk[++stktop]=i;
	}
//	for (int i=1;i<=stktop;i++) printf("stk %d = %d\n",i,stk[i]);
	for (int i=1;i<=n;i++){
		int j=1;
		while (j<=stktop&&a[stk[j]].x<b[i].x) j++;
		//rec[++rectop]=(Rec){0,j<=stktop?max(0,a[stk[j]].y-b[i].y+1):0};
		int last=j<=stktop?max(0,a[stk[j]].y-b[i].y+1):0;
		c[i]=last;
//		printf("case %d: first 0 + %d\n",i,c[i]);
		while (j<=stktop){
			rec[++rectop]=(Rec){a[stk[j]].x-b[i].x+1,j+1<=stktop?max(0,a[stk[j+1]].y-b[i].y+1):0,last};
			last=j+1<=stktop?max(0,a[stk[j+1]].y-b[i].y+1):0;
//			printf("  next %d + %d\n",rec[rectop].t,rec[rectop].u);
			j++;
		}
	}
	sort(rec+1,rec+rectop+1);
	int ans=1e9;
	for (int i=1;i<=n;i++) P.push(c[i]);
	ans=0+P.top();
	for (int i=1,j;i<=rectop;i=j+1){
		for (j=i;j<rectop&&rec[j+1].t==rec[j].t;j++);
		for (int u=i;u<=j;u++){
			Q.push(rec[u].v);
			P.push(rec[u].u);
		}
		while (!Q.empty()){
			if (Q.top()==P.top()) Q.pop(),P.pop();
			else break;
		}
		ans=min(ans,rec[i].t+P.top());
	}
	printf("%d\n",ans);
	return 0;
}