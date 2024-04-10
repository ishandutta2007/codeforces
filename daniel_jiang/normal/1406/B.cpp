// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N],b[N],t,qaq;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		rd(n);
		ll c=0,d=0,cnt=0,ans=-99999999999999;qaq=0;
		for(ll i=1,x;i<=n;i++) rd(a[i]),qaq+=(bool)(a[i]<0);
		sort(a+1,a+n+1);
		if(qaq==n||n==5){
			ans=1;
			for(ll i=n;i>=n-5+1;i--) ans*=a[i];
			wr(ans);puts("");continue;
		}
		for(ll i=0;i<=min(qaq,5ll);i+=2){
			ll sum=1;
			if(n-qaq<5-i) continue;
			for(ll k=1;k<=i;k++) sum*=a[k];
			for(ll k=n;k>=n-(5-i)+1;k--) sum*=a[k];
			ans=max(ans,sum);
		}
		wr(ans);puts("");
	}
	return 0;
}