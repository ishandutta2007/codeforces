#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,Move[8][2];
char s[3000005],t[3000005];
inline int id(register int x,register int y){
	return x*(m+1)+y;
}
struct node{
	int x,y;
}qwq,q[3000005];
int head,tail,step[3000005];
inline bool check(int x){
	memset(step,-1,sizeof(step));
	head=1,tail=0;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++)
			if (s[id(i,j)]=='.'){
				step[id(i,j)]=0;
				qwq.x=i,qwq.y=j;
				q[++tail]=qwq;
			}
	for (register int i=1;i<=n;i++){
		qwq.x=i,qwq.y=0;
		step[id(i,0)]=0;
		q[++tail]=qwq;
		qwq.x=i,qwq.y=m+1;
		step[id(i,m+1)]=0;
		q[++tail]=qwq;
	}
	for (register int i=1;i<=m;i++){
		qwq.x=0,qwq.y=i;
		step[id(0,i)]=0;
		q[++tail]=qwq;
		qwq.x=n+1,qwq.y=i;
		step[id(n+1,i)]=0;
		q[++tail]=qwq;
	}
	while(head<=tail){
		node now=q[head];
		head++;
		register int nowx=now.x,nowy=now.y;
		if (step[id(nowx,nowy)]==x)break;
		for (register int i=0;i<8;i++){
			register int nx=nowx+Move[i][0],ny=nowy+Move[i][1];
			if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&step[id(nx,ny)]==-1){
				qwq.x=nx,qwq.y=ny;
				step[id(nx,ny)]=step[id(nowx,nowy)]+1;
				q[++tail]=qwq;
			}
		}
	}
	head=1,tail=0;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++){
			if (step[id(i,j)]==-1&&s[id(i,j)]=='X'){
				qwq.x=i,qwq.y=j;
				step[id(i,j)]=0;
				q[++tail]=qwq;
			}
			else step[id(i,j)]=-1;
		}
	while(head<=tail){
		node now=q[head];
		head++;
		register int nowx=now.x,nowy=now.y;
		if (step[id(nowx,nowy)]==x)break;
		for (register int i=0;i<8;i++){
			register int nx=nowx+Move[i][0],ny=nowy+Move[i][1];
			if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&step[id(nx,ny)]==-1){
				qwq.x=nx,qwq.y=ny;
				step[id(nx,ny)]=step[id(nowx,nowy)]+1;
				q[++tail]=qwq;
			}
		}
	}
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++){
			if (s[id(i,j)]=='.'&&step[id(i,j)]!=-1)return 0;
			if (s[id(i,j)]=='X'&&step[id(i,j)]==-1)return 0;
		}
	return 1;
}
int main(){
	Move[0][0]=0,Move[0][1]=1;
	Move[1][0]=0,Move[1][1]=-1;
	Move[2][0]=1,Move[2][1]=0;
	Move[3][0]=-1,Move[3][1]=0;
	Move[4][0]=1,Move[4][1]=1;
	Move[5][0]=1,Move[5][1]=-1;
	Move[6][0]=-1,Move[6][1]=1;
	Move[7][0]=-1,Move[7][1]=-1;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%s",t+1);
		for (int j=1;j<=m;j++)s[id(i,j)]=t[j];
	}
	if (n<3||m<3){
		cout<<0<<endl;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				putchar(s[id(i,j)]);
			cout<<endl;
		}
		return 0;
	}
	int l=0,r=1000,x=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))x=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<x<<endl;
	memset(step,-1,sizeof(step));
	head=1,tail=0;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++)
			if (s[id(i,j)]=='.'){
				step[id(i,j)]=0;
				qwq.x=i,qwq.y=j;
				q[++tail]=qwq;
			}
	for (register int i=1;i<=n;i++){
		qwq.x=i,qwq.y=0;
		step[id(i,0)]=0;
		q[++tail]=qwq;
		qwq.x=i,qwq.y=m+1;
		step[id(i,m+1)]=0;
		q[++tail]=qwq;
	}
	for (register int i=1;i<=m;i++){
		qwq.x=0,qwq.y=i;
		step[id(0,i)]=0;
		q[++tail]=qwq;
		qwq.x=n+1,qwq.y=i;
		step[id(n+1,i)]=0;
		q[++tail]=qwq;
	}
	while(head<=tail){
		node now=q[head];
		head++;
		register int nowx=now.x,nowy=now.y;
		if (step[id(nowx,nowy)]==x)break;
		for (register int i=0;i<8;i++){
			register int nx=nowx+Move[i][0],ny=nowy+Move[i][1];
			if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&step[id(nx,ny)]==-1){
				qwq.x=nx,qwq.y=ny;
				step[id(nx,ny)]=step[id(nowx,nowy)]+1;
				q[++tail]=qwq;
			}
		}
	}
	for (register int i=1;i<=n;i++){
		for (register int j=1;j<=m;j++)
			if (step[id(i,j)]==-1)putchar('X');
			else putchar('.');
		cout<<endl;
	}
	return 0;
}