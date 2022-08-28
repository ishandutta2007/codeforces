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
vector<pair<int,int> > ans;
int n,i,del[15005];
vector<int> v[15005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
void merge(int x,int y)
{
	int i;del[x]=1;
	fz0k(i,v[x].size()){
		ans.push_back(make_pair(v[x][i],v[y][i]));
		v[y].push_back(v[x][i]);
	}
}
void solve()
{
	while(pq.size()>1){
		int x=pq.top().second;pq.pop();
		if(v[x].size()!=pq.top().first) continue;
		int y=pq.top().second;pq.pop();
		merge(x,y);pq.push(make_pair(v[y].size(),y));
	}
}
int main()
{
	read(n);
	fz1(i,n){
		v[i].push_back(i);
		pq.push(make_pair(1,i));
	}
	solve();
	int t=1;while(t*2<=n)t*=2;
	if(t!=n){
		fz1(i,n)if(v[i].size()==t) break;
		t=t+t-n;
		while(t--){
			int x=v[i].back();v[i].pop_back();
			del[x]=0;v[x].clear();v[x].push_back(x);
		}
		while(!pq.empty()) pq.pop();
		fz1(i,n){
			if(!del[i]) pq.push(make_pair(v[i].size(),i));
		}
		solve();
	}
	printf("%d\n",ans.size());
	ff(ans,it)printf("%d %d\n",it->first,it->second);
	return 0;
}