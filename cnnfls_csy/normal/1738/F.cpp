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
/*#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif*/
typedef long long i64;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(i64 &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,k,i,j;
int d[1005],fa[1005],vis[1005];
int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
bool cmp(int x,int y){return d[x]>d[y];}
void solve()
{
	scanf("%d",&n);fz1(i,n) scanf("%d",&d[i]),fa[i]=i;
	fz1(i,n) vis[i]=0;
	vector<int> v;fz1(i,n) v.push_back(i);
	sort(v.begin(),v.end(),cmp);
	ff(v,it)if(!vis[*it]){
		vis[*it]=1;
		fz1(j,d[*it]){
			printf("? %d\n",*it);
			fflush(stdout);
			int x;scanf("%d",&x);
			if(vis[x]){
				fa[fnd(*it)]=fnd(x);
				break;
			}
			else{
				vis[x]=1;
				fa[fnd(x)]=fnd(*it);
			}
		}
	}
	printf("!");
	fz1(i,n) printf(" %d",fnd(i));
	puts("");fflush(stdout);
}
int main()
{
	int t;scanf("%d",&t);
	while(t--) solve();
	return 0;
}