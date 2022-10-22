#include <bits/stdc++.h>
using namespace std;
typedef double db;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int T,h,c,t;
void MAIN(){
	read(h),read(c),read(t);
	if(t*2<=c+h){
		puts("2");return;
	}
	db t1=t,h1=h,x=(db)(h+c)/2.0;
	int l=-1,r=1e7;
	while(l+1<r){
		int mid=(l+r)/2;
		if(x+(h1-x)/(db)(2*mid+1)>t)l=mid;
		else r=mid;
	}
	db X1=x+(h1-x)/(db)(2*l+1),X2=x+(h1-x)/(db)(2*l+3);
	if(fabs(X1-t1)<=fabs(X2-t1)) write(l*2+1);
	else write(l*2+3);puts("");
}
int main(){
	read(T);
	while(T--)MAIN();
}