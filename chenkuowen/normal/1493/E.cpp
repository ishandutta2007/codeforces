#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
char a[N],b[N];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s%s",a,b);
	int p=0;
	for(;p<n;++p){
		if(a[p]!=b[p]) break;
		else putchar(a[p]);
	}
	if(p==n) return 0;
	if(p==0){
		for(int i=p;i<n;++i) putchar('1');
		exit(0);
	}
	bool flag=0;
	for(int i=p+1;i<n;++i) 
		if(a[i]!='1') flag=1;
	for(int i=p;i+1<n;++i)
		putchar(b[i]);
	for(int i=p+1;i<n;++i)
		if(b[i]=='1') flag=1;
	if(flag||b[n-1]=='1') putchar('1');
	else putchar('0'); 
	return 0;
}