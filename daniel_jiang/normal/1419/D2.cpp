// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N],ans[N],sum;
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
	rd(n);
	for(ll i=0;i<n;i++) rd(a[i]);
	sort(a,a+n);
	for(ll i=1;i<n;i+=2) ans[i]=a[i/2];
	if(n&1){for(ll i=n-1;i>=0;i-=2) ans[i]=a[n-1-(n-1-i)/2];}
	else{for(ll i=n-2;i>=0;i-=2) ans[i]=a[n-1-(n-1-i)/2];}
	for(ll i=1;i<n-1;i++)
		if(ans[i]<ans[i-1]&&ans[i]<ans[i+1]) sum++;
	wr(sum);puts("");
	for(ll i=0;i<n;i++) wr(ans[i]),putchar(' ');puts("");
	return 0;
}