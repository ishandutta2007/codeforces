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
int n,i,j;
long long m,a[1000005],res[1000005],ans[1000005];
deque<pair<long long,long long> > dq;
long long dk,db;
bool f[1000005];
long long mi[1000005];
int main()
{
	read(n);read(m);
	fz1(i,n-2){
		read(a[i]);
	}
	dk=1;db=0;
	dq.push_back(make_pair(0,m));
	res[0]=0;
	fz1(i,n-2){
		if(dk==1){
			while(!dq.empty()&&dk*dq.back().second+db>a[i]){
				if(dk*dq.back().first+db>a[i]) dq.pop_back();
				else dq.back().second=dk*(a[i]-db);
			}
			f[i]=(!dq.empty()&&dk*dq.back().second+db==a[i]);
		}
		else{
			while(!dq.empty()&&dk*dq.front().first+db>a[i]){
				if(dk*dq.front().second+db>a[i]) dq.pop_front();
				else dq.front().first=dk*(a[i]-db);
			}
			f[i]=(!dq.empty()&&dk*dq.front().first+db==a[i]);
		}
		
		if(f[i]){
			dq.clear();
			dk=1;db=0;
			dq.push_back(make_pair(0,a[i]));
			continue;
		}
		
		bool hv=0;
		if(!dq.empty()){
			hv=1;
		}
		dk*=-1;db=a[i]-db;
		if(dk==-1){
			while(!dq.empty()&&dk*dq.back().second+db>a[i]){
				if(dk*dq.back().first+db<0) dq.pop_back();
				else dq.back().second=dk*(0-db);
			}
			if(hv&&(dq.empty()||dk*dq.front().first+db!=a[i])) dq.push_front(make_pair(dk*(a[i]-db),dk*(a[i]-db)));
		}
		else{
			while(!dq.empty()&&dk*dq.front().first+db>a[i]){
				if(dk*dq.front().second+db<0) dq.pop_front();
				else dq.front().first=dk*(0-db);
			}
			if(hv&&(dq.empty()||dk*dq.back().second+db!=a[i])) dq.push_back(make_pair(dk*(a[i]-db),dk*(a[i]-db)));
		}
		
		if(dq.empty()){
			puts("NO");
			return 0;
		}
		if(dk==1){
			mi[i]=dk*dq.front().first+db;
		}
		else{
			mi[i]=dk*dq.back().second+db;
		}
		res[i]=mi[i];
	}
	
	puts("YES");
	fd1(i,n-2){
		if(f[i]){
			res[i-1]=a[i];
		}
		else if(res[i]!=a[i]){
			res[i-1]=a[i]-res[i];
		}
	}
	fz1(i,n-2){
		if(max(max(abs(res[i-1]),abs(res[i])),abs(res[i-1]+res[i]))!=a[i]){
			res[i]*=-1;
		}
	}
	
	ans[0]=0;
	fz1(i,n-1) ans[i]=ans[i-1]+res[i-1];
	long long dlt=0;
	fz0k(i,n) dlt=min(dlt,ans[i]);
	fz0k(i,n) printf("%lld%c",ans[i]-dlt,spln(i,n));
	return 0;
}