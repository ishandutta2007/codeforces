#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int n,l,k,cnt=0,lst=1;
char c[1000004];
char ans[1003][1003];
int main(){
	for (int i=0;i<1003;i++)for(int j=0;j<1003;j++)ans[i][j]='@';
	read(n),read(l),read(k);
	for (int i=1;i<=n*l;i++) c[i]=getchar();
	sort (c+1,c+n*l+1); 
	for (int i=1;i<=l;i++){
		for (int j=lst;j<=k;j++) ans[j][i]=c[++cnt];
		int p;
		for (p=k;ans[p][i]==ans[k][i];p--);
		p++;
		lst=p;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=l;j++){
			if (ans[i][j]=='@') ans[i][j]=c[++cnt];
		}
	for (int i=1;i<=n;i++,puts("")) for (int j=1;j<=l;j++) printf("%c",ans[i][j]);
}