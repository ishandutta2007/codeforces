#include<bits/stdc++.h>
using namespace std;
const int N=4020;
int T,n,a[N],m,p,pos;bool vis[N];
bitset<4020>b;
void solve(){
	scanf("%d",&n);pos=p=m=n*2;
	memset(vis,0,sizeof(vis));b.reset();b[0]=1;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=m;i;i--){
		vis[a[i]]=1;
		if(vis[p]){
			int dat=pos-i+1;pos=i-1;
			b|=b<<dat;
			while(vis[p])p--;
		}
	}
	puts(b[n]?"YES":"NO");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}