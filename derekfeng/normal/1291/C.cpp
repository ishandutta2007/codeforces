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
int t,n,m,k;
int a[3510];
int main(){
	cin>>t;
	while (t--){
		int ans=0;
		read(n),read(m),read(k);k=min(m-1,k);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=0;i<=k;i++){
			int bigst=1e9;
			for (int j=0;j<=m-1-k;j++){
				bigst=min(bigst,max(a[i+j+1],a[n-(k-i)-(m-1-k-j)]));
			}
			ans=max(ans,bigst);
		}
		write(ans),puts("");
	}
}