// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N],ans,nw;
stack<pair<ll,ll> >c1,c2,qaq,c3;
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
	rd(n);nw=n;
	for(ll i=1;i<=n;i++) rd(a[i]);
	for(ll i=n;i>0;i--){
		if(a[i]==0) continue;
		if(a[i]==1){
			c1.push(make_pair(nw,i));qaq.push(make_pair(nw,i));
			ans++;nw--;
		}
		if(a[i]==2){
			if(c1.empty()){
				puts("-1");return 0;
			}
			pair<ll,ll> x=c1.top();c1.pop();
			c2.push(make_pair(x.first,i));qaq.push(make_pair(x.first,i));
			ans++;
		}
		if(a[i]==3){
			if(c1.empty()&&c2.empty()&&c3.empty()){
				puts("-1");return 0;
			}
			if(!c3.empty()){
				pair<ll,ll> x=c3.top();c3.pop();
				ans+=2;
				c3.push(make_pair(nw,i));
				qaq.push(make_pair(nw,i));qaq.push(make_pair(nw,x.second));
				nw--;
				continue;
			}
			if(!c2.empty()){
				pair<ll,ll> x=c2.top();c2.pop();
				ans+=2;
				c3.push(make_pair(nw,i));
				qaq.push(make_pair(nw,i));qaq.push(make_pair(nw,x.second));
				nw--;
				continue;
			}
			pair<ll,ll> x=c1.top();c1.pop();
			ans+=2;
			c3.push(make_pair(nw,i));
			qaq.push(make_pair(nw,i));qaq.push(make_pair(nw,x.second));
			nw--;
			continue;
		}
	}
	wr(ans);puts("");
	while(!qaq.empty()){
		pair<ll,ll> x=qaq.top();qaq.pop();
		wr(x.first),putchar(' '),wr(x.second),puts("");
	}
	return 0;
}