// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,t;
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
ll ab(ll x){
	if(x<0) return -x;
	return x;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		rd(a);rd(b);rd(c);rd(d);
		if(a==c){
			wr(ab(b-d));puts("");
			continue;
		}
		if(b==d){
			wr(ab(a-c));puts("");
			continue;
		}
		wr(ab(a-c)+ab(b-d)+2);puts("");
	}
	return 0;
}