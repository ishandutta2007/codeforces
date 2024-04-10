#include <bits/stdc++.h>
using namespace std;
void write(long long x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
int T;
ll n,l,r,L,R,ans[300004];
void MAIN(){
	ll d=0;
	L=0,R=1e9;
	ll M=0;
	for (ll i=1;i<=n;i++){
		if (i<n) d+=2*(n-i);
		else d++;
		if (d>=r) R=min(R,i);
		if (d<l) L=i,M=d;
	}
	L++;
	int cnt=0;
	for (ll i=L;i<=R;i++){
		if (i!=n) for (ll j=i+1;j<=n;j++) ans[++cnt]=i,ans[++cnt]=j; 
		else ans[++cnt]=1;
	}
	for (ll i=l-M;i<=r-M;i++) write(ans[i]),putchar(' ');
	puts("");
}
int main(){
	cin>>T;
	while (T--){
		cin>>n>>l>>r;
		MAIN();
	}
}