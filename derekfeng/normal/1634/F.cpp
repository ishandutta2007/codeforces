#include<bits/stdc++.h>
using namespace std;
int n,q,M,a[300004],b[300004];
int num,fib[300004];
void add(int i,int x){
	if(i>n)return;
	if(a[i]==0)num--;
	a[i]=((a[i]+x)%M+M)%M;
	if(a[i]==0)num++;
}
int main(){
	scanf("%d%d%d",&n,&q,&M);
	fib[1]=fib[2]=1%M;
	for(int i=3;i<=n;i++)fib[i]=(fib[i-2]+fib[i-1])%M;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]),b[i]=(b[i]-a[i]+M)%M;
		a[i]=(b[i]-b[i-1]+M)%M;
		if(i>1)a[i]=(a[i]-b[i-2]+M)%M;
		if(a[i]==0)num++;
	}
	while(q--){
		char op[3];int l,r;scanf("%s%d%d",op,&l,&r);
		int m=(*op=='A')?-1:1;
		if(l==r)add(l,m),add(l+1,-m),add(l+2,-m);
		else add(l,m),add(r+1,-m*(fib[r-l+1]+fib[r-l])%M),add(r+2,-m*fib[r-l+1]);
		puts(num==n?"YES":"NO");
	}
}