#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int B=200;
int n,m,opt,x,y,p[100005],q[100005],nxt[100005];
int c[100005];
int getnxt(int x,int y){
	for (int i=1;i<=y;i++)x=p[x];
	return x;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)p[i]=read(),q[p[i]]=i;
	for (int i=1;i<=n;i++)nxt[i]=getnxt(i,B);
	while(m--){
		opt=read(),x=read(),y=read();
		if (opt==1){
			swap(p[x],p[y]);
			swap(q[p[x]],q[p[y]]);
			int qwq=p[x];
			for (int i=1;i<=B;i++)c[i]=qwq,qwq=p[qwq];
			qwq=x;
			for (int i=1;i<=B;i++)nxt[qwq]=c[B-i+1],qwq=q[qwq];
			qwq=p[y];
			for (int i=1;i<=B;i++)c[i]=qwq,qwq=p[qwq];
			qwq=y;
			for (int i=1;i<=B;i++)nxt[qwq]=c[B-i+1],qwq=q[qwq];
		}
		if (opt==2){
			while(y>=B)x=nxt[x],y-=B;
			printf("%d\n",getnxt(x,y));
		}
	}
	return 0;
}