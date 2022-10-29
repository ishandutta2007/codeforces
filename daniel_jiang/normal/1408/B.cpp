// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=105;
ll t,n,k,a[N],qaq,ans;
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
		rd(n);rd(k);qaq=0;
		for(ll i=1;i<=n;i++) rd(a[i]);
		for(ll i=2;i<=n;i++) qaq+=(a[i]!=a[i-1]);
		if(k==1&&qaq){
			wr(-1);puts("");continue;
		}
		qaq++;
		if(qaq<=k){
			wr(1);puts("");continue;
		}
		qaq-=k;
		wr((qaq+k-2)/(k-1)+1);puts("");
	}
	return 0;
}