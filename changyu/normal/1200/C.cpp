#include<cstdio>
#define int long long
int n,m,q,d,nn,mm,Sx,Sy,Tx,Ty;
int G(int a,int b){return b?G(b,a%b):a;}
signed main(){
	scanf("%I64d%I64d%I64d",&n,&m,&q);
	d=G(n,m);nn=n/d,mm=m/d;
	for(;q--;){
	  scanf("%I64d%I64d%I64d%I64d",&Sx,&Sy,&Tx,&Ty);
	  puts((Sy-1)/(Sx==1?nn:mm)==(Ty-1)/(Tx==1?nn:mm)?"YES":"NO");
	}return 0;
}