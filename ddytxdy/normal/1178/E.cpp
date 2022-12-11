#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int len,m;char c[N],a[N];
int main(){
	scanf("%s",c+1);
	len=strlen(c+1);
	for(int i=1,j=len;i<=j;i++,j--){
		int p1=1e9,p2=1e9;
		if(i<j&&c[i]==c[j])p1=i,p2=j;
		else if(i+1<j&&c[i+1]==c[j])p1=i+1,p2=j;
		else if(i<j-1&&c[i]==c[j-1])p1=i,p2=j-1;
		else if(i+1<j-1&&c[i+1]==c[j-1])p1=i+1,p2=j-1;
		if(p1!=1e9)a[++m]=c[p1],i=p1,j=p2;
		else {a[0]=c[i];break;}
	}
	for(int i=1;i<=m;i++)putchar(a[i]);
	if(a[0])putchar(a[0]);
	for(int i=m;i;i--)putchar(a[i]);
	return 0;
}