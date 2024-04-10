#include<bits/stdc++.h>
using namespace std;
int T,n,k1,k2;
void solve(){
	scanf("%d%d%d",&n,&k1,&k2);int d1=-1e9,d2=-1e9;
	for(int i=1,x;i<=k1;i++)scanf("%d",&x),d1=max(d1,x);
	for(int i=1,x;i<=k2;i++)scanf("%d",&x),d2=max(d2,x);
	puts(d1>d2?"YES":"NO");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}