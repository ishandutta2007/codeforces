#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,b[N];
bool solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) b[i]=0;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),b[x]=1;
	for(int i=1;i<=m;i++) b[i]+=b[i-1];
	for(int i=1;i<=m;i++) if(!(b[i]-b[i-1]))
		for(int j=1;i*j<=m;j++) if(b[j]-b[j-1]) if(b[min(i*j+j-1,m)]-b[i*j-1]) return 0;
	return 1;
}
int main(){
	int t;scanf("%d",&t);
	while(t--) puts(solve()?"Yes":"No");
	return 0;
}