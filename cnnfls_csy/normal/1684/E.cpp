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
	FILE* _=freopen("1.in","r",stdin);
#endif
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
int n,m,i,j,a[100005],c[100005],pre[100005];
struct ds
{
	int blk,sz;int cc[100005];
	vector<int> big;
	void init(int n){int i;sz=0;fz1(i,n)cc[i]=0;big.clear();blk=ceil(sqrt(n));}
	void ins(int x)
	{
		sz++;if(x<=blk) cc[x]++; else big.insert(lower_bound(big.begin(),big.end(),x),x);
	}
	int query(int x)
	{
		int ans=sz,i;
		fz1(i,blk){
			if(cc[i]*i<=x) ans-=cc[i],x-=cc[i]*i;
			else{
				return ans-x/i;
			}
		}
		ff(big,it){
			if(*it<=x) x-=*it,ans--; else break;
		}
		return ans;
	}
}b;
void solve()
{
	read(n);read(m);int ans=n;
	fz0g(i,n+2) c[i]=pre[i]=0;
	fz1(i,n){
		read(a[i]);
		if(a[i]<n) c[a[i]]++;
	}
	fz0g(i,n) pre[i]+=!!c[i],pre[i+1]+=pre[i];
	sort(a+1,a+n+1);
	j=n;b.init(n);
	fd0k(i,n){
		int t=i+1-pre[i];if(t>m) continue;
		while(j&&a[j]>i){
			int k=j;while(k&&a[k]==a[j])k--;
			b.ins(j-k);j=k;
		}
		ans=min(ans,b.query(m));
	}
	while(j){
		int k=j;while(k&&a[k]==a[j])k--;
		b.ins(j-k);j=k;
	}
	ans=min(ans,b.query(m));
	printf("%d\n",ans);
}
int main()
{
	int t;read(t);while(t--)solve();
	return 0;
}