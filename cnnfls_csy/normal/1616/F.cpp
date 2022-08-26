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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int tt,n,m,i,j,k,l,num,g[75][75],cid,px[265],py[265];
vector<int> xs[265];
int fir[265];
vector<int> add(vector<int> a,vector<int> b)
{
	int i;
	fz0g(i,m) a[i]=(a[i]+b[i])%3;
	return a;
}
int ins(vector<int> v)
{
	int i;
	fz1(i,num)while(v[fir[i]]){
		v=add(v,xs[i]);
	}
	i=m;while(i>=0&&!v[i]) i--;
	if(i==0) return 0;
	if(i!=-1){
		if(v[i]==2) v=add(v,v);
		xs[++num]=v;
		fir[num]=i;
	}
	return 1;
}
void solve()
{
	num=0;read(n);read(m);memset(g,0,sizeof(g));cid=0;
	fz1(i,m){
		int x,y,z;read(x);read(y);read(z);if(x>y)swap(x,y);g[x][y]=++cid;px[cid]=x;py[cid]=y;
		if(z!=-1){vector<int> v;v.push_back(z-1);fz1(j,m) v.push_back(j==i);ins(v);}
	}
	fz1(i,n)fz(j,i+1,n)if(g[i][j])fz(k,j+1,n)if(g[i][k]&&g[j][k]){
		vector<int> v;v.push_back(0);
		fz1(l,m)if(l==g[i][j]||l==g[i][k]||l==g[j][k]) v.push_back(1); else v.push_back(0);
		if(!ins(v)){puts("-1");return;}
	}
	fz1(i,m){
		vector<int> v;v.push_back(-1);
		fz1(j,m) v.push_back(i==j); 
		fz0k(j,3){
			v[0]=j;
			if(ins(v)){
				printf("%d%c",j+1,spln(i,m));
				break;
			}
		}
	}
}
int main()
{
	read(tt);
	while(tt--){
		solve();
	}
	return 0;
}