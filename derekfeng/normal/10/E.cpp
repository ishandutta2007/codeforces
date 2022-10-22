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
void outputno(){
	puts("-1");exit(0); 
}
int n,ans=2e9;
int a[403];
int G(int x){
	int ret=0;
	for (int i=1;i<=n;i++)ret+=x/a[i],x%=a[i];
	return ret;
}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=2;i<=n;i++){
		int xtmp=a[i-1]-1,x=a[i-1]-1,cnt=0;
		for (int j=i;j<=n;j++){
			cnt+=x/a[j],x%=a[j];
			if (cnt+1<G(xtmp-x+a[j])) ans=min(ans,xtmp-x+a[j]); 
		}
	}
	if (ans==2e9) outputno();
	write(ans);
}