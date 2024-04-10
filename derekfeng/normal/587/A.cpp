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
int n;
int a[2000004],ans=0;
int main(){
	read(n);
	for (int i=1;i<=n;i++){
		int x;
		read(x),a[x]++;
	}
	for (int i=0;i<=2e6;i++){
		ans+=a[i]%2;
		a[i+1]+=a[i]/2;
	}
	write(ans);
}