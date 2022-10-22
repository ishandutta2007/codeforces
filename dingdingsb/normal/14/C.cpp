#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
#define TP int
int a,b,c,d;
struct node{
	int x,y;
	node(int X,int Y){
		x=X,y=Y;
	}
	bool operator<(const node b)const{
		return x!=b.x?x<b.x:y<b.y;
	}
	bool operator>(const node b)const{
		return x!=b.x?x>b.x:y>b.y;
	}
};
int X,Y;
map<node,int>M;int ans=0;
map<int,bool>xx,yy;
map<int,map<int,map<int,map<int,bool> > > >XY;
int main(){
	int x1,y1,x2,y2;
	for(int i=1;i<=4;i++){
		cin>>x1>>y1>>x2>>y2;
		int x=x1,y=y1;
		if(M[node(x,y)])
			ans++;
		if(M[node(x,y)]==2)
			printf("NO"),exit(0);
		M[node(x,y)]++;
		if(!xx[x])
			X++,xx[x]=true;
		if(!yy[y])
			Y++,yy[y]=true;
		x=x2,y=y2;
		if(M[node(x,y)])
			ans++;
		if(M[node(x,y)]==2)
			printf("NO"),exit(0);
		M[node(x,y)]++;
		if(!xx[x])
			X++,xx[x]=true;
		if(!yy[y])
			Y++,yy[y]=true;
		if(XY[x1][y1][x2][y2]||XY[x2][y2][x1][y1])
			printf("NO"),exit(0);
		XY[x1][y1][x2][y2]=XY[x2][y2][x1][y1]=true;
		if(x1==x2&&y1==y2)
			printf("NO"),exit(0);
	}
	if(ans==4 && X==2 && Y==2)
		printf("YES");
	else
		printf("NO");
}