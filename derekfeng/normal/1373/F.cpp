#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int T,n,a[1000004],b[1000004]; 
void solve() {
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	ll need=0,add=0,extra=1e10;
	for(int i=n;i>0;i--){
		if(b[i]<need){puts("NO");return;}
		ll v=b[i]-a[i];
		ll toadd=min(extra,max(0ll,v-need));
		add+=toadd;
		extra=min(extra-toadd,b[i]-need-toadd);
		need=max(0ll,need-v);
	}
	puts(add>=need?"YES":"NO");
}
int main() {read(T);while(T--)solve();}