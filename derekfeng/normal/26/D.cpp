#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
typedef long double ldb;
ldb num[2000004];
int n,m,K;
ldb C(int a,int b){
	return num[a]-num[b]-num[a-b];
}
int main(){
	read(n),read(m),read(K);
	if (n+K<m) puts("0.000000"); 
	else if (K>=m) puts("1.000000");
	else{
		for (int i=2;i<=n+min(m,K+1);i++)
			num[i]=num[i-1]+log(i*1.0);
		cout<<1.0-exp(C(n+m,n+K+1)-C(n+m,n));
	}
}