/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,x,y,z,t;
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
		rd(a);rd(b);rd(c);rd(x);rd(y);rd(z);
		ll ans=min(c,y)*2;
		c-=ans/2;y-=ans/2;
		if(c+a<z) ans-=(z-a-c)*2;
		wr(ans);puts("");
	}
	return 0;
}