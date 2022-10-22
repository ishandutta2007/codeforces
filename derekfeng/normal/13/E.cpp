#include <bits/stdc++.h>
using namespace std;
const int M=320;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
int gonxt[100004],c[100004],a[100004]; 
int nxt(int x){
	return min(n,x/M*M+M);
}
int main(){
	read(n),read(q); 
	for (int i=0;i<n;i++)read(a[i]);
	for (int i=n-1;i>=0;i--){
		if (i+a[i]>=nxt(i)) gonxt[i]=min(n,i+a[i]),c[i]=1;
		else gonxt[i]=gonxt[i+a[i]],c[i]=c[i+a[i]]+1;
	}
	while(q--){
		int oper,x;read(oper),read(x),x--;
		if (oper==1){
			int ret=0,lst,lstt;
			while (x!=n) ret+=c[x],lst=x,x=gonxt[x];
			while (lst<n) lstt=lst,lst+=a[lst];
			write(lstt+1),putchar(' '),write(ret),puts("");
			continue;
		}
		int b;read(b);a[x]=b;
		if (x+b>=nxt(x))gonxt[x]=min(n,x+b),c[x]=1;
		else gonxt[x]=gonxt[x+b],c[x]=c[x+b]+1;
		for (int i=x-1;i>=x/M*M;i--){
			if (i+a[i]>=nxt(i))gonxt[i]=min(n,i+a[i]),c[i]=1;
			else gonxt[i]=gonxt[i+a[i]],c[i]=c[i+a[i]]+1;
		}
	}
}