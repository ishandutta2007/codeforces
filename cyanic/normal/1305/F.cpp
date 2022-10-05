#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
mt19937 rnd((long int)(new char));
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005,lim=1000000;
int cur[N],p[N],flag[N],vis[N];
int n,m,cnt,ans;
ll a[N],v[N];

void init(){
	rep(i,2,lim){
		if(flag[i]) continue;
		p[++cnt]=i;
		for(int j=i+i;j<=lim;j+=i)
			flag[j]=1;
	}
}

void doit(ll p){
	ll ret=0;
	for(int i=1;i<=n&&ret<=ans;i=cur[i]){
		ll low=a[i]/p*p,high=low+p;
		ret+=(low==0?high-a[i]:min(a[i]-low,high-a[i]))*(cur[i]-i);
	}
	ans=min((ll)ans,ret);
}

int main(){
	read(n),ans=n,init();
	rep(i,1,n) read(a[i]);
	sort(a+1,a+n+1);
	per(i,n,1)
		if(a[i]==a[i+1]) cur[i]=cur[i+1];
		else cur[i]=i+1;
	m=n;
	rep(i,1,n) v[i]=a[i];
	m=unique(v+1,v+m+1)-v-1;
	rep(i,1,5) doit(p[i]),vis[i]=1;
	if(m<=80){
		rep(j,1,m){
			ll now=v[j];
			for(int i=1;i<=cnt&&(ll)p[i]*p[i]<=now;i++)
				if(now%p[i]==0){
					if(!vis[i]) doit(p[i]),vis[i]=1;
					while(now%p[i]==0) now/=p[i];
				}
			if(now>=2) doit(now);
		}
		cout<<ans<<endl;
		return 0;
	}
	init();
	for(;clock()<2*CLOCKS_PER_SEC;){
		int x=(rnd()%m+m)%m+1;
		int y=(rnd()%m+m)%m+1;
		while(x==y){
			x=(rnd()%m+m)%m+1;
			y=(rnd()%m+m)%m+1;
		}
		ll now=abs(v[x]-v[y]);
		for(int i=1;i<=cnt&&(ll)p[i]*p[i]<=now;i++)
			if(now%p[i]==0){
				if(!vis[i]) doit(p[i]),vis[i]=1;
				while(now%p[i]==0) now/=p[i];
			}
		if(now>=2) doit(now);
	}
	cout<<ans<<endl;
	return 0;
}