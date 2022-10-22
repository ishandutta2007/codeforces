#include<bits/stdc++.h>
using namespace std;
int T,n,a[210],b[210];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		bool ok=true;
		for(int i=1;i<=n;i++)ok&=(b[i]==a[i]||b[i]==a[i]+1);
		puts(ok?"YES":"NO");
	}
	return 0;
}