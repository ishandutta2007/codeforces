/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+5,INF=(ll)(1e10);
ll n,a[N];
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
ll qwq(ll l,ll r){
	if(l>r) return 0;
	if(l==r) return (bool)(a[l]!=0);
	ll m=INF,sum=0,lst=l;
	for(ll i=l;i<=r;i++) m=min(m,a[i]);
	for(ll i=l;i<=r;i++) a[i]-=m;
	sum=m;
	if(sum>r-l+1) return r-l+1;
	for(ll i=l;i<=r;i++)
		if(a[i]==0){
			sum+=qwq(lst,i-1);
			if(sum>r-l+1) return r-l+1;
			lst=i+1;
		}
	sum+=qwq(lst,r);
	return min(sum,r-l+1);
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(ll i=1;i<=n;i++) rd(a[i]);
	wr(qwq(1,n));
	return 0;
}