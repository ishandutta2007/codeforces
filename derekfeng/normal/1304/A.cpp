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
int main(){
	int T;cin>>T;
	while (T--){
		int l,r,x,y;
		read(l),read(r),read(x),read(y);
		if ((r-l)%(x+y)!=0) puts("-1");
		else cout<<(r-l)/(x+y)<<"\n";
	}
}