#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
#include<set>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
typedef pair<ll,ll> P;
#define fi first
#define se second

int n,m;
P w[100010];
set<P> st;
priority_queue<ll,vector<ll>,greater<ll> > que;
struct C{
	ll l,r,k;
}c[1000010]; int top;
bool operator<(const C &x,const C &y){
	return x.l<y.l;
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++){
		w[i].fi=read();
		w[i].se=read();
	}
	w[++n]=(P){0,0};
	sort(w+1,w+n+1);
	set<P>(w+1,w+n+1).swap(st);
	ll pt=0,b=0;
	for (int i=1;i<=n;){
		while (!que.empty()&&b+que.top()-pt<=w[i].fi){
			if (0<que.top()-pt){
				c[++top]=(C){b,b+que.top()-pt-1,pt};
			}
			b+=que.top()-pt,pt=que.top()+1;
			while (!que.empty()&&que.top()<=pt) pt=max(pt,que.top()+1),que.pop();
		}
		int t=i; bool f=0;
		if (b<w[t].fi) c[++top]=(C){b,w[t].fi-1,pt};
		pt+=w[t].fi-b; b=w[t].fi;
//		while (i<=n&&w[t].fi==w[i].fi&&w[i].se<=pt) i++,f=1;
		while (i<=n&&w[t].fi==w[i].fi){
			f=f||w[i].se<=pt;
			if (w[i].se>=pt) que.push(w[i].se);
			i++;
		}
		if (!f) c[++top]=(C){b,b,pt},que.push(pt);
		b++;
	}
	while (!que.empty()){
		if (0<que.top()-pt){
			c[++top]=(C){b,b+que.top()-pt-1,pt};
		}
		b+=que.top()-pt,pt=que.top()+1;
		while (!que.empty()&&que.top()<=pt) pt=max(pt,que.top()+1),que.pop();
	}
	if (b<=int(1e9)) c[++top]=(C){b,int(1e9),pt};
//	for (int i=1;i<=top;i++) printf("%d: %lld %lld  %lld\n",i,c[i].l,c[i].r,c[i].k);
	while (m--){
		ll x=read(),y=read();
		if (st.count((P){x,y})){
			puts("LOSE"); continue;
		}
		int p=upper_bound(c+1,c+top+1,(C){x,0,0})-c-1;
		if (p&&c[p].r>=x&&y==c[p].k+x-c[p].l) puts("LOSE");
		else puts("WIN");
	}
	return 0;	
}