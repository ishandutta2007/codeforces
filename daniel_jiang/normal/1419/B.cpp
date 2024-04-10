// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,cnt;
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
		rd(n);ll cnt=0;
		for(ll i=1;i<=100;i++){
			ll qwq=(1<<i)-1,nw=(qwq+1)*qwq/2;
			if(nw<=n) n-=nw,cnt++;
			else break;
		}
		wr(cnt);puts("");
	}
	return 0;
}