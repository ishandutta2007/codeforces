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
int n,a[5003];
int dfs(int l,int r){
	int MINN=a[l];
	for (int i=l+1;i<=r;i++) MINN=min(a[i],MINN);
	int ret=MINN;
	for (int i=l;i<=r;i++) a[i]-=MINN;
	for (int i=l;i<=r;i++){
		if (a[i]==0) continue;
		int j=i+1;
		for (;j<=r && a[j];j++);
		j--;
		ret+=dfs(i,j);
		i=j;
	}
	return min(r-l+1,ret);
}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	write(dfs(1,n));
}