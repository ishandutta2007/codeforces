// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],b[N],fa[N],p,cnt,dis,ans;
vector<ll>awa[N];pair<ll,ll>c[N];
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
inline bool cmp(pair<ll,ll> x,pair<ll,ll>y){return a[x.first]+b[x.second]>a[y.first]+b[y.second];}
inline ll found(ll k){return (fa[k]==k)?k:(fa[k]=found(fa[k]));}
int main(){
	rd(n),rd(m);
	for(ll i=1;i<=n;i++) rd(a[i]);
	for(ll i=1;i<=m;i++) rd(b[i]),fa[i]=i;
	for(ll i=1,qaq,qwq;i<=n;i++){
		rd(qwq);
		for(ll j=1;j<=qwq;j++) rd(qaq),cnt++,c[cnt]=make_pair(i,qaq);
	}
	sort(c+1,c+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++){
		dis=a[c[i].first]+b[c[i].second];
		if(awa[c[i].first].size()){
			if(found(awa[c[i].first][awa[c[i].first].size()-1])==found(c[i].second)) ans+=dis;
			else{
				fa[found(awa[c[i].first][awa[c[i].first].size()-1])]=found(c[i].second);
				awa[c[i].first].push_back(c[i].second);
			}
		}
		else awa[c[i].first].push_back(c[i].second);
	}
	wr(ans);puts("");
	return 0;
}