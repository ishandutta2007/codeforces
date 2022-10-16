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
const int MAXN=65;
ll n,k,lim[MAXN];
ll f[MAXN][2][2];
int check(int pos,int x){return (lim[pos]==-1 || lim[pos]==x);}
ll dp(){
	memset(f,0,sizeof f);
	ll ret=0;
	//f[1]
	rep(l1,0,1)rep(l2,0,1){
		if(!check(1,l1) || !check(n,l2))continue;
		if(!l1 && !l2)f[1][0][1]=1;
		if(!l1 && l2)f[1][1][0]=1;
	}
	int mid=n/2;
	rep(i,1,mid-1){
		rep(lim1,0,1)rep(lim2,0,1)rep(lx,0,1)rep(rx,0,1){
			//if(!lx && !rx)printf("f[%d][%d]:%d\n",lim1,lim2,f[1][lim1][lim2]);
			//f[i][l][r][lim1][lim2]lx,rx
			if(!check(i+1,lx) || !check(n-i,rx))continue;
			if(!lim1 && lx && !rx)continue;
			if(!lim2 && lx && rx)continue;
			if(!lx && !rx)f[i+1][lim1][1]+=f[i][lim1][lim2];
			if(!lx && rx)f[i+1][1][lim2]+=f[i][lim1][lim2];
			if(lx && !rx)f[i+1][1][lim2]+=f[i][lim1][lim2];
			if(lx && rx)f[i+1][lim1][1]+=f[i][lim1][lim2];
		}
	}
	if(odd(n)){
		//
		mid++;
		rep(lim1,0,1)rep(lim2,0,1)rep(x,0,1){
			if(!check(mid,x))continue;
			if(!lim2 && x)continue;
		//	printf("x:%d lim1:%d lim2:%d(%d)\n",x,lim1,lim2,f[mid-1][lim1][lim2]);
			f[mid][lim1][1]+=f[mid-1][lim1][lim2];	
		} 
	}
//	printf("mid:%d\n",mid);
	rep(lim1,0,1)rep(lim2,0,1)ret+=f[mid][lim1][lim2];/*printf("%d %d %d\n",lim1,lim2,f[mid][lim1][lim2]);*/
	//0
	int flag=1;rep(i,1,n)if(!check(i,0))flag=0; 
	return ret-flag;
}
int main(){
	cin>>n>>k;
	if(n==2){
		if(k==1)return printf("01"),0;
		return printf("-1"),0;
	}
	rep(i,1,n)lim[i]=-1;
	lim[1]=0;
	ll val=dp();
	if(val<k)return printf("-1\n"),0;
	
	rep(i,2,n){
		//
		lim[i]=0;
		ll val=dp();
		if(k>val)lim[i]=1,k-=val;
	}
	rep(i,1,n)printf("%d",lim[i]);
	return 0;
}