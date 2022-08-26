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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
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
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[200005],b[200005],l[200005],r[200005],vis[200005];
long long pre[200005];
vector<int> v[200005];
void solve()
{
	read(n);read(m);fz1(i,n)read(a[i]);fz1(i,n)read(b[i]);
	fz1(i,n) pre[i]=pre[i-1]+a[i]-b[i];
	set<int> s;fz1(i,n) if(pre[i]) s.insert(i);
	fz0g(i,n) v[i].clear();
	fz1(i,m){read(l[i]);read(r[i]);l[i]--;v[l[i]].push_back(i);v[r[i]].push_back(i);vis[i]=s.count(l[i])+s.count(r[i]);}
	queue<int> qx;
	fz1(i,m) if(vis[i]==0) vis[i]=-1,qx.push(i);
	while(!qx.empty()){
		int x=qx.front();qx.pop();
		for(set<int>::iterator it=s.lower_bound(l[x]+1);it!=s.end()&&*it<=r[x];it=s.erase(it)){
			ff(v[*it],it2) if(!--vis[*it2]) qx.push(*it2),vis[*it2]=-1;
		}
	}
	if(s.empty()) puts("YES");else puts("NO");
}
int main()
{
	int t;read(t);
	while(t--) solve();
	return 0;
}