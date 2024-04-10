#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void readi(ll &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0'); 
}
int T,n,ans[300005];
ll h[300005],b[300005];
bool vis[300005];
void go(int x){
	vis[x]=1;
	if (h[(x+1)%n]>b[x]) ans[x]=x;
	else{
		if (vis[(x+1)%n]) ans[x]=ans[(x+1)%n];
		else go((x+1)%n),ans[x]=ans[(x+1)%n];
	}
}
void MAIN(){
	ll MIN=1e14;
	read(n);
	for (int i=0;i<n;i++) readi(h[i]),readi(b[i]),vis[i]=0,MIN=min(MIN,h[i]);
	if (n==1){
		write(h[0]);return;
	}
	bool ok=1;
	for (int i=0;i<n && ok;i++) if (b[i]<h[(i+1)%n]) ok=0;
	if (ok){
		write(MIN);return;
	}
	for (int i=0;i<n;i++){
		if (vis[i]) continue;
		go(i);
	}
	ll res=0,anss=1e18;
	for (int i=0;i<n;i++)
		if (ans[i]==i) res+=h[(i+1)%n]-b[i];
	for (int i=0;i<n;i++){
		if (ans[(i+n-1)%n]==(i+n-1)%n) anss=min(anss,res+b[(i-1+n)%n]);
		else anss=min(anss,res+h[i]);
	}
	write(anss);
}
int main(){
	read(T);
	while (T--){
		MAIN();puts("");
	}
}