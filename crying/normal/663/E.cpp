#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=(1<<21)+10,MAXM=1e5+10;
ll n,m,a[23][MAXM],A[MAXN],B[MAXN],f[MAXN],g[MAXN],h[MAXN],ans;
char tmp;
ll ppc(int x){
	int ret=0;
	while(x){
		ret++;
		x-=lowbit(x);
	}
	return ret;
}
void fwt_xor(ll* f,ll* a,int mode){
	rep(i,0,(1<<n)-1){
		f[i]=a[i];
	}
	for(int i=1;i<(1<<n);i<<=1){
		for(int o=i<<1,j=0;j<(1<<n);j+=o){
			for(int k=0;k<i;k++){
				ll x=f[j+k],y=f[i+j+k];
				f[j+k]=x+y;
				f[i+j+k]=x-y;
				if(mode==-1){
					f[j+k]/=2;
					f[i+j+k]/=2;
				} 
			}
		}
	} 
}
int main(){
	scanf("%lld%lld",&n,&m);ans=n*m;
	rep(i,1,n){
		rep(j,1,m){
			scanf(" %c",&tmp);a[i][j]=tmp-'0';
		}
	} 
	rep(j,1,m){
		int ret=0;
		rep(i,1,n){
			if(a[i][j])ret|=(1<<(i-1));
		}
		A[ret]++;
	}
	rep(i,0,(1<<n)-1){
		B[i]=min(ppc(i),n-ppc(i));
	}
	fwt_xor(f,A,1);
	fwt_xor(g,B,1);
	rep(i,0,(1<<n)-1){
		h[i]=f[i]*g[i]; 
	}
	fwt_xor(h,h,-1);
	rep(i,0,(1<<n)-1)ans=min(ans,h[i]);
	printf("%lld",ans); 
	return 0;
}