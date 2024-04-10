#include <stdio.h>
#include <string.h>
int mn(int a,int b){
	if(a==-1)return b;
	if(b==-1)return a;
	return a<b?a:b;
}
int ch(int a,int b){
	if(a==-1)return 0;
	if(b==-1)return 0;
	int c=a-b;
	if(c<0)c*=-1;
	return ((c%2)==0);
}	
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,m,i,j,a,b,p1,q1,p2,q2;
	int w,x,y,z;
	scanf("%d %d %d %d %d %d",&n,&m,&i,&j,&a,&b);
	if((i==1||i==n)&&(j==1||j==m)){
		printf("0");return 0;
	}
	if((i+a>n)&&(i-a<1)||(j+b>m)&&(j-b<1)){
		printf("Poor Inna and pony!");
		return 0;
	}
	p1=q1=-1;
	if((n-i)%a==0)p1=(n-i)/a;
	if((i-1)%a==0)q1=(i-1)/a;
	p2=q2=-1;
	if((m-j)%b==0)p2=(m-j)/b;
	if((j-1)%b==0)q2=(j-1)/b;
	w=x=y=z=-1;
	if(ch(p1,p2))w=mx(p1,p2);
	if(ch(p1,q2))x=mx(p1,q2);
	if(ch(q1,p2))y=mx(q1,p2);
	if(ch(q1,q2))z=mx(q1,q2);
	n=mn(mn(w,x),mn(y,z));
	if(n==-1)
		printf("Poor Inna and pony!");
	else
		printf("%d",n);
}