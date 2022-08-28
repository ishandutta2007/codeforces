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
int n,m,i,j,k,fa[2005];
struct ii
{
	int x,y,z,id;
}a[2005],b[2005];
vector<pair<int,int> > ans;
vector<ii> stk;
bool cmp(ii x,ii y)
{
	return x.x<y.x;
}
ii operator -(ii x,ii y)
{
	return (ii){x.x-y.x,x.y-y.y,0,0};
}
int crs(ii x,ii y)
{
	return x.x*y.y-x.y*y.x;
}
int fnd(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=fnd(fa[x]); 
}
void merge(int x,int y)
{
	if(fnd(x)==fnd(y))return;
	fa[fnd(x)]=fnd(y);ans.push_back(make_pair(x,y)); 
}
void solve(ii x,ii y,ii z)
{
	merge(x.id,y.id);
	int i;
	fz1(i,n){
		if(a[i].z!=z.z) continue;
		if(a[i].x==x.x&&a[i].y==x.y) continue;
		if(a[i].x==y.x&&a[i].y==y.y) continue;
		if(a[i].x==z.x&&a[i].y==z.y) continue;
		if(abs(crs(y-x,z-x))!=abs(crs(x-a[i],y-a[i]))+abs(crs(x-a[i],z-a[i]))+abs(crs(z-a[i],y-a[i]))) continue;
		solve(x,y,a[i]);
		solve(a[i],z,x);
		solve(a[i],z,y);
		return;
	}
	fz1(i,n){
		if(a[i].x==x.x&&a[i].y==x.y) continue;
		if(a[i].x==y.x&&a[i].y==y.y) continue;
		if(a[i].x==z.x&&a[i].y==z.y) continue;
		if(abs(crs(y-x,z-x))!=abs(crs(x-a[i],y-a[i]))+abs(crs(x-a[i],z-a[i]))+abs(crs(z-a[i],y-a[i]))) continue;
		merge(x.id,a[i].id);
	}
}
void print()
{
	printf("%d\n",ans.size());
	ff(ans,it){
		printf("%d %d\n",it->first-1,it->second-1);
	}
}
int main()
{
	read(n);
	fz1(i,n){
		read(a[i].x);
		read(a[i].y);
		read(a[i].z);
		a[i].id=i;fa[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	stk.clear();
	fz1(i,n){
		while(stk.size()>1&&crs(stk.back()-stk[stk.size()-2],a[i]-stk[stk.size()-2])>=0) stk.pop_back();
		stk.push_back(a[i]);
	}
	ff(stk,it) b[++m]=*it;m--;
	reverse(a+1,a+n+1);
	stk.clear();
	fz1(i,n){
		while(stk.size()>1&&crs(stk.back()-stk[stk.size()-2],a[i]-stk[stk.size()-2])>=0) stk.pop_back();
		stk.push_back(a[i]);
	}
	ff(stk,it) b[++m]=*it;m--;
	fz1(i,m){
		b[i+m]=b[i];
	}
	i=1;while(i<=m&&b[i].z==b[1].z){
		i++;
	}
	if(i>m){
		int t=1;while(t<=n&&a[t].z==b[1].z)t++;
		if(t==n+1){
			printf("%d\n",n-1);
			fz1(i,n-1){
				printf("%d %d\n",i-1,n-1);
			}
			return 0;
		}
		fz1(i,m){
			solve(b[i],b[i+1],a[t]);
		}
		print();
		return 0;
	}
	j=i;
	while(j<=m&&b[j].z==b[i].z) j++;
	while(j<=m&&b[j].z==b[1].z) j++;
	if(j<=m){
		puts("Impossible");
		return 0;
	}
	j=i;
	while(j<=m&&b[j].z==b[i].z) j++;
	if(j>m) j=1;
	while(j<=m&&b[j].z==b[i].z) j++;
	fz1(k,m){
		if(b[k].z==b[k+1].z){
			if(b[k].z==b[1].z){
				solve(b[k],b[k+1],b[i]);
			}
			else{
				solve(b[k],b[k+1],b[j]);
			}
		}
	}
	print();
	return 0;
}