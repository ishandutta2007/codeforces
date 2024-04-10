#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	int res=1;
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
	if (ch=='-') res=-1,ch=getchar(); 
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
    x*=res;
}
void outputno(){
	puts("No");exit(0);
}
int n,x[100004],y[100004];
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	if (n%2) outputno();
	for (int i=1,j=n/2+1;j<n;i++,j++)
		if (x[i+1]-x[i]!=x[j]-x[j+1] || y[i+1]-y[i]!=y[j]-y[j+1]) outputno();
	puts("Yes");
}