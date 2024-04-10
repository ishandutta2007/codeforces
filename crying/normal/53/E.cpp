#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
int n,m,k;
int u[110],v[110];
ll f[1<<10][1<<10],ans;
int Count(int x){
	int cnt=0;
	while(x)cnt+=(x&1),x>>=1;
	return cnt;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		a--;b--;
		u[i*2-1]=a;v[i*2-1]=b;
		u[i*2]=b;v[i*2]=a;
		f[(1<<a)|(1<<b)][(1<<a)|(1<<b)]=1;
	}
	rep(i,1,(1<<n)-1){
		rep(j,1,(1<<n)-1){
			if(j>i)continue;
			if((i&j)+(i^j)==i){
			//	printf("f[%d][%d]:%d\n",i,j,f[i][j]);
				rep(k,1,m*2){
					int a=u[k],b=v[k];
					if(!((1<<a)&i) || (i&(1<<b)))continue; //aib
				//	printf("a:%d b:%d\n",a,b);
					int rest=j;if(j&(1<<a))rest-=(1<<a);
					if((1<<b)<=rest)continue; //
					if(j&(1<<a))f[i|(1<<b)][j-(1<<a)+(1<<b)]+=f[i][j];
					else f[i|(1<<b)][j+(1<<b)]+=f[i][j];
				}
			}
		}
	}
	rep(j,1,(1<<n)-1){
		if(Count(j)!=k)continue;
		ans+=f[(1<<n)-1][j];
	}
	printf("%lld",ans);
	return 0;
}