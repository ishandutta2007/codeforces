#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,a[300004],ans;
ull h[300004],f[300004],hs[300004];
int calc(int x){
	int mx=1,cur=h[1],ret=0;
	for(int i=x+1;i<=n&&a[i]!=1;i++){
		mx=max(mx,a[i]);
		if(i>=mx&&i-mx+1<=x&&(hs[i]^hs[i-mx])==f[mx])ret++;
	}
	return ret;
}
int main(){
	for(int i=0;i<6556;i++);
	mt19937_64 rng(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)h[i]=rng(),f[i]=f[i-1]^h[i];
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),hs[i]=hs[i-1]^h[a[i]];
	for(int i=1;i<=n;i++)if(a[i]==1)ans+=calc(i)+1;
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)hs[i]=hs[i-1]^h[a[i]];
	for(int i=1;i<=n;i++)if(a[i]==1)ans+=calc(i);
	printf("%d",ans);
}