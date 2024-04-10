#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5007;
const int INF=1e9+7;
map<int,bool>p;
int q=0,n,m,ans=0,cnt=0;
int a[N],g[N],b[N*10];
bool is[N*10];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int val(int x){
	int ans=0;
	rep(f,cnt){
		int i=b[f];
		if(i>sqrt(x))break;
		if(x%i==0){
			int t=0;
			while(x%i==0)x/=i,t++;
			if(p.count(i))ans-=t;
			else ans+=t;
		}
	}
	if(x>1){
		if(p.count(x))ans--;
		else ans++;
	}
	return ans;
}
int main(){
	REP(i,2,(5e4)){
		if(!is[i])b[++cnt]=i;
		rep(j,cnt){
			if(i*b[j]>(5e4))break;
			is[i*b[j]]=1;
			if(i%b[j]==0)break;
		}
	}
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,m){
		int x; scanf("%d",&x);
		p[x]=1;
	}
	rep(i,n){
		ans+=val(a[i]);
		q=gcd(a[i],q);
		g[i]=-val(q);
	}
	for(int i=n;i;i--){
		if(g[i]>0){
			ans+=g[i]*i;
			rep(j,i-1)g[j]-=g[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}