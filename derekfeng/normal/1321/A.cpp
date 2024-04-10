#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
int n,r[100004],p[100004],ans,now;
int main(){
	read(n),ans=n;
	for (int i=1;i<=n;i++) read(r[i]);
	for (int i=1;i<=n;i++){
		read(p[i]);
		if (r[i]==p[i]) r[i]=0,p[i]=0;
		if (r[i]==1) now=1;
	}
	int c1=0,c2=0;
	for (int i=1;i<=n;i++){
		if (r[i]==1) c1++;
		if (p[i]==1) c2++;
	}
	if (!now) puts("-1");
	else cout<<c2/c1+1;
}