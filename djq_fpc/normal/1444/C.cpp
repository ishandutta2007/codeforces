#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
long long ans;
int n,m,k,sk,ban[500005],i,j,fa[500005],sz[500005],dis[500005],cnt,fr[500005];
stack<int> stk;
map<pair<int,int>,int> mp;
vector<pair<int,int> > v[500005];
int f(int x,int y)
{
	if(x>y)swap(x,y);
	if(mp.count(make_pair(x,y))){
		return mp[make_pair(x,y)];
	}
	else return mp[make_pair(x,y)]=++cnt;
}
pair<int,int> fnd(int x)
{
	if(fa[x]==x) return make_pair(x,0);
	pair<int,int> t=fnd(fa[x]);
	return make_pair(t.first,dis[x]^t.second);
}
void undo()
{
	int x=stk.top();stk.pop();
	sz[fa[x]]-=sz[x];fa[x]=x;dis[x]=0;
}
bool merge(int x,int y,bool ins)
{
	int d=1;
	pair<int,int> fx=fnd(x);
	d^=fx.second;x=fx.first;
	pair<int,int> fy=fnd(y);
	d^=fy.second;y=fy.first;
	if(x==y){
		return !d;
	}
	if(sz[x]>sz[y]) swap(x,y);
	if(ins) stk.push(x);
	dis[x]=d;sz[y]+=sz[x];fa[x]=y;
	return 1;
}
void solve(int x)
{
	int flg=1;
	ff(v[x],it){
		if(!merge(it->first,it->second,1)){
			flg=0;break;
		}
	}
	if(!flg) ans--;
	while(!stk.empty()) undo();
}
int main()
{
	read(n);read(m);read(k);sk=k;
	fz1(i,n) read(fr[i]);
	fz1(i,n){
		fa[i]=i;
		sz[i]=1;
	}
	fz1(i,m){
		int x,y;
		read(x);read(y);
		if(fr[x]==fr[y]){
			if(!merge(x,y,0)){
				ban[fr[x]]=1;
			}
		}
		else{
			int t=f(fr[x],fr[y]);
			v[t].push_back(make_pair(x,y));
		}
	}
	fz1(i,k)if(ban[i]) sk--;
	ans=1ll*sk*(sk-1)/2;
	ff(mp,it){
		if(ban[it->first.first]||ban[it->first.second]) continue;
		solve(it->second);
	}
	cout<<ans<<endl;
	return 0;
}