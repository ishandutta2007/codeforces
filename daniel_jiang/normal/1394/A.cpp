/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,m,d,a[N],b[N],c[N],cntb,cntc,ans;
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
	rd(n);rd(d);rd(m);
	for(ll i=1;i<=n;i++) rd(a[i]);
	sort(a+1,a+n+1);
	for(ll i=n;i>0;i--)
		if(a[i]>m) b[++cntb]=a[i];
		else c[++cntc]=a[i];
	for(ll i=1;i<=n;i++) b[i]+=b[i-1],c[i]+=c[i-1];
	for(ll i=0;i<=n;i++)
		ans=max(ans,c[i]+b[(n-i)/(d+1)+(bool)((n-i)%(d+1))]);
	wr(ans);puts("");
	return 0;
}