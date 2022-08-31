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
int t,n,q,i,j,a[200005];
int seq[35],cnt;
multiset<long long> s[35];
vector<long long> v[35];
void init(int n)
{
	int tmp=n,i;cnt=0;
	for(i=2;i*i<=tmp;i++)if(tmp%i==0){
		seq[++cnt]=n/i;
		while(tmp%i==0)tmp/=i;
	}
	if(tmp>1) seq[++cnt]=n/tmp;
	fz1(i,cnt) s[i].clear(),v[i].clear(),v[i].resize(seq[i],0ll);
	fz1(i,cnt){
		fz0k(j,n) v[i][j%seq[i]]+=a[j];
		fz0k(j,seq[i]) s[i].insert(v[i][j]);
	}
}
void print()
{
	long long ans=0;int i;
	fz1(i,cnt){
		ans=max(ans,seq[i]*(*s[i].rbegin()));
	}
	printf("%lld\n",ans);
}
void solve()
{
	read(n);read(q);fz0k(i,n)read(a[i]);init(n);
	print();
	while(q--){
		int x;read(x);x--;
		fz1(i,cnt){
			s[i].erase(s[i].find(v[i][x%seq[i]]));
			v[i][x%seq[i]]-=a[x];
		}
		read(a[x]);
		fz1(i,cnt){
			v[i][x%seq[i]]+=a[x];
			s[i].insert(v[i][x%seq[i]]);
		}
		print();
	}
}
int main()
{
	read(t);
	while(t--){
		solve();
	}
	return 0;
}