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
int n,m,i,j,tt,a[300005],c[300005],b[300005],vis[300005];
vector<int> ans;
bool check(int x)
{
	int s=0,i;
	fz1(i,n) vis[i]=0;
	fz1(i,n) b[i]=a[(i+x-1)%n+1];
	fz1(i,n)if(!vis[i]){
		s++;int x=i;
		while(!vis[x]){
			vis[x]=1;x=b[x];
		}
	}
	return n-s<=m;
}
int main()
{
	ios_base::sync_with_stdio(0);
	read(tt);
	while(tt--){
		read(n);read(m);
		fz1(i,n)read(a[i]);
		fz0k(i,n)c[i]=0;
		fz1(i,n)c[(i-a[i]+n)%n]++;
		ans.clear();
		fz0k(i,n)if(c[i]>=n-m-m){
			if(check(i)) ans.push_back(i);
		}
		printf("%d",ans.size());
		ff(ans,it)printf(" %d",*it);
		puts("");
	}
	return 0;
}