#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[100004],d[100004],p[100004],maxn=-1,pos;
int main(){
	read(n);for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) d[i]=d[i-1]|a[i];
	for (int i=n;i>0;i--) p[i]=p[i+1]|a[i];
	for (int i=1;i<=n;i++){
		int res=d[i-1]|p[i+1];
		if (maxn<(a[i]|res)-res) maxn=(a[i]|res)-res,pos=i;
	}
	swap(a[1],a[pos]);
	for (int i=1;i<=n;i++) write(a[i]),putchar(' ');
}