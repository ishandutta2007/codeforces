// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=4e5+5;
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
struct CartesianTree{
	struct node{
		int id,v,fa,ls,rs;
	}tr[N];
	inline void init(){tr[0].id=tr[0].v=tr[0].ls=tr[0].rs=tr[0].fa=0;}
	inline void insert(int x,int y,int z){
		tr[x].id=x;tr[x].v=y;tr[x].fa=z;tr[x].ls=tr[x].rs=0;
		int k=x-1;
		while(tr[k].v>tr[x].v) k=tr[k].fa;
		tr[x].ls=tr[k].rs;tr[k].rs=x;
		tr[x].fa=k;tr[tr[x].rs].fa=x;
	}
}CT;
ll n,kk,sum,qaq,u,v,ans,x[N],t[N];
pair<ll,ll> p;
priority_queue<pair<ll,ll> >q;
inline ll xrjtxdy(ll x,ll y){
	ll l=x%y,s=y-l,r=x/y;
	return r*r*s+(r+1)*(r+1)*l;
}
int main(){
	rd(n);rd(kk);
	for(ll i=1;i<=n;i++){
		rd(x[i]),ans+=x[i]*x[i],t[i]=2,qaq=x[i]>>1;
		if(x[i]>1) q.push(make_pair(x[i]*x[i]-qaq*qaq-(x[i]-qaq)*(x[i]-qaq),i));
	}
	for(ll i=n+1;i<=kk;i++){
		p=q.top(),u=p.first,v=p.second,q.pop(),ans-=u,t[v]++;
		if(x[v]>=t[v]) q.push(make_pair(xrjtxdy(x[v],t[v]-1)-xrjtxdy(x[v],t[v]),v));
	}
	wr(ans);puts("");
	return 0;
}