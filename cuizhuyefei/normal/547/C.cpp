#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 500500;
inline int power(int a, int n){int res=1; rep(i,1,n)res*=a; return res;}
int n,prime[N],len,mrk[N],mu[N],a[N],cnt[N];
ll ans;
bool occ[N];
int s[26],dy[(1<<20)+1];
int main() { //freopen("1.in","r",stdin);
	int q; read(n); read(q); rep(i,1,n) read(a[i]); rep(i,1,19) dy[1<<i]=i;
	per(i,n,1) n=max(n,a[i]);
	rep(i,2,n) {
		if (!mrk[i]) prime[++len]=i;
		rep(j,1,len) {
			int v=prime[j]*i; if (v>n) break;
			mrk[v]=prime[j]; if (i%prime[j]==0) break;
		}
	}
	mu[1]=1;
	rep(i,2,n) if (!mrk[i]) mu[i]=-1;
	else {
		int v=mrk[i],lst=i/v; if (lst%v==0) mu[i]=0; else mu[i]=mu[v]*mu[lst];
	}
	while (q--) {
		int x; read(x); int v=occ[x] ? -1 : 1; occ[x]^=1;
		int len=0,t=a[x]; //printf("t = %d %d\n",t,mrk[1]);
		while (mrk[t]) {if (!len||s[len-1]!=mrk[t]) s[len++]=mrk[t]; t/=mrk[t];}
		if (t>1&&(!len||s[len-1]!=t)) s[len++]=t; //printf("len = %d\n",len);
		rep(i,0,(1<<len)-1) {
			int t=i,S=1; while (t) {int bit=t&-t; t-=bit; S*=s[dy[bit]];}
			ll del=(1LL*(cnt[S]+v)*(cnt[S]+v-1)-1LL*cnt[S]*(cnt[S]-1))/2;
		//	printf("%d %lld %d %d\n",S,del,mu[S],cnt[S]);
			cnt[S]+=v; ans+=del*mu[S]; 
		}
		printf("%lld\n",ans);
	}
	return 0;
}