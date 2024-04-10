// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2005,M=1e6+5;
ll n,m,s[M],x[N],y[N],u[N],v[N],ans=1000000000;
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
	rd(n);rd(m);
	for(ll i=1;i<=n;i++) rd(u[i]),rd(v[i]);
	for(ll i=1;i<=m;i++) rd(x[i]),rd(y[i]);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			if(x[j]>=u[i]&&y[j]>=v[i])
				s[x[j]-u[i]]=max(s[x[j]-u[i]],y[j]-v[i]+1);
	for(ll i=1000001;i>=0;i--)
		s[i]=max(s[i],s[i+1]),ans=min(ans,s[i]+i);
	wr(ans);puts("");
	return 0;
}