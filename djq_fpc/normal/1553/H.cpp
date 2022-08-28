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
int n,m,i,j,a[1200005],ch[1200005][2],val[1200005],d,cnt=1,ans[1200005],res[1200005];
vector<pair<int,int> > v;
void ins(int x)
{
	int i,t=1;
	for(i=m-1;i>=0;i--){
		if(!ch[t][(x>>i)&1]){
			ch[t][(x>>i)&1]=++cnt;
		}
		t=ch[t][(x>>i)&1];
	}
	val[t]=x; 
}
int qrymin(int t,int y)
{
	int i;
	for(i=d-1;i>=0;i--){
		int c=((y>>i)&1);
		if(!ch[t][c])c^=1;
		t=ch[t][c];
	}
	return val[t]^y;
}
int qrymax(int t,int y)
{
	int i;
	for(i=d-1;i>=0;i--){
		int c=!((y>>i)&1);
		if(!ch[t][c])c^=1;
		t=ch[t][c];
	}
	return val[t]^y;
}
void dfs1(int x,int dep)
{
	if(dep==d){
		if(!ch[x][0]||!ch[x][1])return;
		fz0k(j,(1<<(d+1))){
			res[j]=min(res[j],abs(qrymin(ch[x][1],j)-qrymax(ch[x][0],j)));
			res[j]=min(res[j],abs(qrymax(ch[x][1],j)-qrymin(ch[x][0],j)));
		}
		return;
	}
	if(ch[x][0])dfs1(ch[x][0],dep-1);
	if(ch[x][1])dfs1(ch[x][1],dep-1);
}
int main()
{
	read(n);read(m);
	fz1(i,n){
		read(a[i]);
		ins(a[i]);
	}
	fz0k(i,(1<<m))ans[i]=0x3f3f3f3f;
	for(i=0;i<m;i++){
		d=i;
		fz0k(j,(1<<(i+1))){
			res[j]=0x3f3f3f3f;
		}
		dfs1(1,m-1);
		fz0k(j,(1<<m)) ans[j]=min(ans[j],res[j&((1<<(i+1))-1)]);
	}
	fz0k(i,(1<<m))printf("%d ",ans[i]);
	return 0;
}