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
int n,m,i,j,a[200005],ord[200005],tmp[200005];
int id(int x,int y){return (x-1)*m+y;}
bool check(int x,int y)
{
	int i,j;fz1(i,m) ord[i]=i;swap(ord[x],ord[y]);
	fz1(i,n)fz1(j,m-1) if(a[id(i,ord[j])]>a[id(i,ord[j+1])]) return 0;
	return 1;
}
void solve()
{
	read(n);read(m);
	int c=0;
	fz1(i,n)fz1(j,m) assert(id(i,j)==++c);
	fz1(i,n)fz1(j,m)read(a[id(i,j)]);
	if(check(1,1)){
		printf("%d %d\n",1,1);
		return;
	}
	fz1(i,n){
		vector<int> pos;
		fz1(j,m) tmp[j]=a[id(i,j)];
		sort(tmp+1,tmp+m+1);
		fz1(j,m) if(a[id(i,j)]!=tmp[j]) pos.push_back(j);
		if(pos.empty()) continue;
		if(pos.size()>6){
			puts("-1");return;
		}
		ff(pos,it1)ff(pos,it2){
			if(check(*it1,*it2)){
				printf("%d %d\n",*it1,*it2);
				return;
			}
		}
		puts("-1");return;
	}
}
int main()
{
	int t;read(t);while(t--)solve();
	return 0;
}