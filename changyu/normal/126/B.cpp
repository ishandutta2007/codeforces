#include<bits/stdc++.h>
const int N=1e6+3;
int n,za[N],p;
char a[N];
int main(){
	scanf("%s",a+1),n=strlen(a+1);
	za[1]=n;
	for(int i=2,j=0;i<=n;i++){
		if(j+za[j]>i)za[i]=std::min(j+za[j]-i,za[i-j+1]);
		for(;i+za[i]<=n&&a[1+za[i]]==a[i+za[i]];++za[i]);
		if(i+za[i]>j+za[j])j=i;
		if(!p&&i+za[i]-1==n)p=i;
	}
	for(int i=2;i<=n;i++){
		if(i<p&&za[i]>=za[p])return 0*printf("%s\n",a+p);
		if(i>p&&i+za[i]-1==n)return 0*printf("%s\n",a+i);
	}
	return 0*puts("Just a legend");
}