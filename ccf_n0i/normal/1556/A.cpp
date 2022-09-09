#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	if((n+m)&1){puts("-1");return;}
	if(n+m==0){puts("0");return;}
	if(n==m)puts("1");else puts("2");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}