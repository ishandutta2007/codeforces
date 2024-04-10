#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int o=1e5+10;
struct Matrix{long long a[2][2];}f[o*40],z;
inline Matrix merge(Matrix A,Matrix B){
	Matrix C;
	for(int i=0;i<2;++i) for(int j=0,k;j<2;++j)
		for(C.a[i][j]=1e18,k=0;k<2;++k) C.a[i][j]=min(C.a[i][j],A.a[i][k]+B.a[k][j]);
	return C;
}
int n,dx[2][o],dy[2][o],m;long long ans;
inline int dis(int laye,int i,int x,int y){
	int res=abs(x-dx[i][laye])+abs(y-dy[i][laye]);
	if(!i&&x<=dx[i][laye]) res+=2;
	if(i&&y<=dy[i][laye]) res+=2;
	return res;
}
void build(int id,int l,int r){
	if(r==l+1){
		for(int i=0;i<2;++i) for(int j=0;j<2;++j) f[id].a[i][j]=dis(l,i,dx[j][r],dy[j][r]);
		return;
	}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md,r);
	f[id]=merge(f[id<<1],f[(id<<1)|1]);
}
Matrix query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return f[id];
	int md=l+r>>1;
	if(qr<=md) return query(id<<1,ql,qr,l,md);
	if(md<=ql) return query((id<<1)|1,ql,qr,md,r);
	return merge(query(id<<1,ql,qr,l,md),query((id<<1)|1,ql,qr,md,r));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i) scanf("%d%d%d%d",&dx[0][i],&dy[0][i],&dx[1][i],&dy[1][i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int X1,Y1,X2,Y2,c1,c2;m--;){
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		if((c1=max(X1,Y1))==(c2=max(X2,Y2))){printf("%d\n",abs(X1-X2)+abs(Y1-Y2));continue;}
		if(c1>c2) swap(X1,X2),swap(Y1,Y2),swap(c1,c2);
		if(c1+1==c2){
			printf("%d\n",min(dis(c1,0,X2,Y2)+abs(X1-dx[0][c1])+abs(Y1-dy[0][c1]),dis(c1,1,X2,Y2)+abs(X1-dx[1][c1])+abs(Y1-dy[1][c1])));
			continue;
		}
		z=query(1,c1,c2-1);ans=1e18;
		for(int i=0;i<2;++i) for(int j=0;j<2;++j)
			ans=min(ans,abs(dx[i][c1]-X1)+abs(dy[i][c1]-Y1)+z.a[i][j]+dis(c2-1,j,X2,Y2));
		printf("%lld\n",ans);
	}
	return 0;
}