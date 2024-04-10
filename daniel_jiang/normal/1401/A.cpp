/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,T;
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
	rd(T);
	while(T--){
		rd(n);rd(k);
		if(n<k){
			wr(k-n);puts("");
			continue;
		}
		if(n==k){
			wr(0);puts("");
			continue;
		}
		if((n-k)&1){
			wr(1);puts("");
			continue;
		}
		wr(0);puts("");
	}
	return 0;
}