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
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int a[103],b[103],d[103],ans[103];
int main(){
	read(n); 
	for (int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
	sort (b+1,b+1+n,cmp);
	for (int i=1;i<=n;i++){
		if (b[i]==b[i-1]) d[i]=d[i-1];
		else d[i]=i-1; 
	}
	read(m);
	while (m--){
		int k,pos;read(k),read(pos);
		int wants=k-d[k];
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (a[i]>b[k]) ans[++cnt]=a[i];
			if (a[i]==b[k] && wants>0){
				ans[++cnt]=a[i];
				wants--;
			}
		}
		write(ans[pos]);puts("");
	}
}