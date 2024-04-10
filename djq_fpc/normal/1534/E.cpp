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
int n,m,i,j,k,ans,pre[505];
queue<int> qx;
vector<int> v0,v1;
int main()
{
	scanf("%d%d",&n,&m);
	memset(pre,-1,sizeof(pre));
	pre[0]=0;qx.push(0);
	while(!qx.empty()){
		int x=qx.front();qx.pop();
		fz0g(i,m){
			if(x+i<=n&&x>=(m-i)){
				int t=x+i-(m-i);
				if(-1==pre[t]){
					pre[t]=x;
					qx.push(t);
				}
			}
		}
	}
	if(pre[n]==-1){
		puts("-1");fflush(stdout);
		return 0;
	}
	fz1(i,n){
		v1.push_back(i);
	}
	int x,t;
	x=n;
	while(x){
		t=(pre[x]+m-x)/2;
		vector<int> t0,t1;
		fz1(i,t){
			t1.push_back(v0.back());
			v0.pop_back();
		}
		fz1(i,m-t){
			t0.push_back(v1.back());
			v1.pop_back();
		}
		printf("?");
		ff(t1,it) printf(" %d",*it);
		ff(t0,it) printf(" %d",*it);
		puts("");fflush(stdout);
		int xx;scanf("%d",&xx);ans^=xx;
		while(!t1.empty()){
			v1.push_back(t1.back());
			t1.pop_back();
		}
		while(!t0.empty()){
			v0.push_back(t0.back());
			t0.pop_back();
		}
		x=pre[x];
	}
	printf("! %d\n",ans);fflush(stdout); 
	return 0;
}