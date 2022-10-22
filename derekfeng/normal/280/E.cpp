#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-11;
struct func{
	db A,B,C;
	func(db A=0,db B=0,db C=0):A(A),B(B),C(C){}
}f[18004],nf[18004];
func moving(func ori,db h){return func(ori.A,-2.0*ori.A*h+ori.B,h*h*ori.A-h*ori.B+ori.C);}
int M,nM,n;
db q,a,b,num[6003];
db l[18004],r[18004];
db nl[18004],nr[18004];
db fv(db x,int i){return x*x*f[i].A+x*f[i].B+f[i].C;}
db minpts(int i){
	db sym=-f[i].B/2/f[i].A;
	if(sym<l[i])return l[i];
	if(sym>r[i])return r[i];
	return sym;
}
db getmin(int i){
	db xs=minpts(i);
	return fv(xs,i);
}
db ans[6003],good[6003];
int main(){
	scanf("%d%lf%lf%lf",&n,&q,&a,&b);
	for(int i=1;i<=n;i++)scanf("%lf",&num[i]);
	l[++M]=1,r[M]=q,f[M]=func(1,-2*num[1],num[1]*num[1]);
	for(int i=2;i<=n;i++){
		int pos;db ret=-1;
		for(int j=1;j<=M;j++){
			db tmp=getmin(j);
			if(tmp<ret||ret<0)ret=tmp,pos=j;
		}
		nM=0;
		for(int j=1;j<pos;j++)nl[++nM]=l[j]+a,nr[nM]=r[j]+a,nf[nM]=moving(f[j],a);
		db ax=minpts(pos);
		good[i]=ax;
		nl[++nM]=l[pos]+a,nr[nM]=ax+a,nf[nM]=moving(f[pos],a);
		if(fabs(a-b)>eps)nl[++nM]=ax+a,nr[nM]=ax+b,nf[nM]=func(0,0,ret);
		nl[++nM]=ax+b,nr[nM]=r[pos]+b,nf[nM]=moving(f[pos],b);
		for(int j=pos+1;j<=M;j++)nl[++nM]=l[j]+b,nr[nM]=r[j]+b,nf[nM]=moving(f[j],b);
		for(int j=1;j<=nM;j++)nf[j].A++,nf[j].B+=-2*num[i],nf[j].C+=num[i]*num[i];
		M=nM;
		for(int j=1;j<=M;j++)l[j]=nl[j],r[j]=nr[j],f[j]=nf[j];
		while(l[M]>q)M--;
	}
	int pos;db ret=-1;
	for(int i=1;i<=M;i++){
		db rr=r[i];
		r[i]=min(r[i],q);
		if(l[i]<r[i]+eps){
			db tmp=getmin(i);
			if(tmp<ret||ret<0)ret=tmp,pos=i;
		}
		r[i]=rr;
	}
	db rr=r[pos];
	r[pos]=min(r[pos],q);
	ans[n]=minpts(pos);
	r[pos]=rr;
	if(fabs(a-b)<eps)for(int i=n-1;i;i--)ans[i]=ans[i+1]-a;
	else for(int i=n;i>1;i--){
		db L=good[i]+a,R=good[i]+b;
		if(L-eps<ans[i]&&ans[i]<R+eps)ans[i-1]=good[i];
		else if(ans[i]>R)ans[i-1]=ans[i]-b;
		else ans[i-1]=ans[i]-a;
	}
	for(int i=1;i<=n;i++)printf("%.8lf ",ans[i]);puts("");
	printf("%.8lf",ret);
}