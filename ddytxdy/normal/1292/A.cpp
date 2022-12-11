#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,q,a[2][N];
struct node{
	int f[2][2];
	void init(){memset(f,0,sizeof(f));}
	node operator +(const node &b){
		node c;c.init();
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					c.f[i][j]|=f[i][k]&b.f[k][j];
		return c;
	}
}t[N*4];
node init(int x){
	node y;y.init();
	if(a[0][x])y.f[0][0]=1;
	if(a[1][x])y.f[1][1]=1;
	if(a[0][x]&&a[1][x])y.f[1][0]=y.f[0][1]=1;
	return y;
}
void build(int x,int l,int r){
	if(l==r){t[x]=init(l);return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
}
void change(int x,int l,int r,int p){
	if(l==r){t[x]=init(p);return;}
	int mid=(l+r)>>1;
	if(p<=mid)change(x<<1,l,mid,p);
	else change(x<<1|1,mid+1,r,p);
	t[x]=t[x<<1]+t[x<<1|1];
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)a[0][i]=a[1][i]=1;
	build(1,1,n);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);x--;
		a[x][y]^=1;change(1,1,n,y);
		puts(t[1].f[0][1]?"Yes":"No");
	}
	return 0;
}