// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,lw;
vector<pair<ll,ll> >qaq;
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
inline ll lower(ll x){
	ll qaq=1;
	while(qaq<x) qaq<<=1;
	return qaq>>1;
}
inline void calc(ll x){
	for(ll i=1;i<lw;i<<=1)
		for(ll j=0;j<lw;j+=i<<1)
			for(ll k=0;k<i;k++){
				ll p=j+k,q=j+k+i,fl=(p>n)||(q>n);
				if(!fl) !x?qaq.push_back((pair<ll,ll>){p+1,q+1}):qaq.push_back((pair<ll,ll>){n-p,n-q});
			}
}
int main(){
	rd(n),lw=lower(n);
	calc(0),calc(1);
	wr(qaq.size()),puts("");
	for(ll i=0;i<qaq.size();i++)printf("%lld %lld\n",qaq[i].first,qaq[i].second);
	return 0;
}