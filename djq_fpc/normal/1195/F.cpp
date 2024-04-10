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
int n,m,i,j,s[300005],lst[300005],ql[100005],ans[100005];
struct ii
{
	int x,y;
};
bool operator <(ii x,ii y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
bool operator ==(ii x,ii y)
{
	return x.x==y.x&&x.y==y.y;
}
vector<ii> a[100005],b[100005],all;
vector<int> v[100005];
void add(int x,int y)
{
	while(x<=n){
		s[x]+=y;
		x+=(x&-x);
	}
}
int qry(int x)
{
	int ss=0;
	while(x){
		ss+=s[x];
		x-=(x&-x);
	}
	return ss;
}
int main()
{
	read(n);
	fz1(i,n){
		read(m);
		while(m--){
			ii x;
			read(x.x);read(x.y);
			a[i].push_back(x);
		}
		a[i].push_back(a[i][0]);
		fz1(j,a[i].size()-1){
			ii t=(ii){a[i][j].x-a[i][j-1].x,a[i][j].y-a[i][j-1].y};
			int g=__gcd(abs(t.x),abs(t.y));
			t.x/=g;t.y/=g;
			b[i].push_back(t);
			all.push_back(t);
		}
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	read(m);
	fz1(i,m){
		int x;read(ql[i]);read(x);
		v[x].push_back(i);
	}
	fz1(i,n){
		ff(b[i],it){
			int t=upper_bound(all.begin(),all.end(),*it)-all.begin();
			if(lst[t]){
				add(lst[t],-1); 
			}
			add(lst[t]=i,1);
		}
		ff(v[i],it){
			ans[*it]=qry(n)-qry(ql[*it]-1);
		}
	}
	fz1(i,m){
		printf("%d\n",ans[i]);
	}
	return 0;
}