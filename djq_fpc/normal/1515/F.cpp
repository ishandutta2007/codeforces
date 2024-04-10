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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,fa[300005],vis[300005],px[300005],py[300005];
long long x,a[300005],sum1;
vector<int> bi[300005];
priority_queue<pair<long long,int> > pq;
int fnd(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
int solve(int t)
{
	vis[t]=1;
	printf("%d\n",t);
	int x=fnd(px[t]);
	int y=fnd(py[t]);
/*	if(x==y){
		a[x]-=::x;
		return;
	}*/
	if(bi[x].size()>bi[y].size()){
		swap(x,y);
	}
	fa[x]=y;a[y]+=a[x];a[y]-=::x;
	ff(bi[x],it) bi[y].push_back(*it);
	return y;
}
int main()
{
	read(n);read(m);read(x);
	fz1(i,n){
		fa[i]=i;
		read(a[i]);sum1+=a[i];
		pq.push(make_pair(a[i],i));
	}
	if(sum1<1ll*x*(n-1)){
		puts("NO");
		return 0;
	}
	fz1(i,m){
		int x,y;
		read(x);read(y);
		bi[x].push_back(i);
		bi[y].push_back(i);
		px[i]=x;py[i]=y;
	}
	puts("YES");
	while(n>1){
		long long memv=pq.top().first;
		int t=pq.top().second;pq.pop();
		if(fnd(t)!=t||a[t]!=memv) continue;
		while(!bi[t].empty()){
			if(vis[bi[t].back()]||fnd(px[bi[t].back()])==fnd(py[bi[t].back()])){
				bi[t].pop_back();
				continue;
			}
			break;
		}
		if(bi[t].empty()) continue;
		int tt=bi[t].back();
		bi[t].pop_back();
		n--;
		int nt=solve(tt);
		pq.push(make_pair(a[nt],nt));
	}
	return 0;
}