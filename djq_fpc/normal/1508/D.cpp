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
const double pi=acos(-1);
int n,m,i,j,f[2005],vis[2005],t;
struct ii
{
	double x,y;
	int id;
}a[2005],bse;
bool cmp(ii x,ii y)
{
	return atan2(x.y,x.x)<atan2(y.y,y.x);
}
vector<pair<int,int> > ans;
void upd(int x,int y)
{
	ans.push_back(make_pair(x,y));
	swap(f[x],f[y]);
}
bool check(int x,int y)
{
	memset(vis,0,sizeof(vis));
	while(!vis[x]){
		vis[x]=1;x=f[x];
	}
	return !vis[y];
}
int main()
{
	cin>>n;
	fz1(i,n){
		cin>>a[i].x>>a[i].y>>f[i];
		a[i].id=i;
		if(f[i]!=i) t=i;
	}
	if(!t){
		puts("0");
		return 0;
	}
	swap(a[t],a[n]);
	bse=a[n];n--;
	fz1(i,n){
		a[i].x-=a[n+1].x;
		a[i].y-=a[n+1].y;
	}
	sort(a+1,a+n+1,cmp);
	a[n+1]=a[1];
	fz1(i,n){
		double t=atan2(a[i+1].y,a[i+1].x)-atan2(a[i].y,a[i].x);
		if(t<0)t+=pi+pi;
		if(t>=pi+pi)t-=pi;
		if(t<=pi&&check(a[i].id,a[i+1].id)){
			upd(a[i].id,a[i+1].id);
		}
	}
	fz1(i,n){
		upd(t,f[t]);
	}
	cout<<ans.size()<<endl;
	ff(ans,it) cout<<it->first<<' '<<it->second<<endl;
	return 0;
}