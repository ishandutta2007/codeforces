#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 555555;
ll n,s;int cnt[N],mid,qz[N],fa[N];
bool solve(int dep, int n, ll s, int lst){
	if(dep==2){memset(cnt,0,4*(n+3));cnt[1]=1;}
	if(!n)return 1;
	ll L=max(2*n-s,1LL),R=min(1LL*lst*mid,1LL*n),k=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(n-mid<=s-n&&2LL*(s-n)<=1LL*(n-mid)*(n-mid+1))k=mid,L=mid+1;else R=mid-1;//WA
	}
	if(!k)return 0;
	//if(mid==3)printf("%d %d %lld: %d\n",dep,n,s,k);
	cnt[dep]=k;return solve(dep+1,n-k,s-n,k);
}
int main() {
	scanf("%lld%lld",&n,&s);
	if(!(s>=2LL*n-1&&s<=1LL*n*(n+1)/2)){puts("No");return 0;}
	int L=1,R=n,res=n;cnt[1]=1;
	while(L<=R){
		mid=(L+R)>>1;
		if(solve(2,n-1,s-n,1))res=mid,R=mid-1;else L=mid+1;
	}
	mid=res;solve(2,n-1,s-n,1);rep(i,1,n)qz[i]=qz[i-1]+cnt[i];
	puts("Yes");
	rep(i,2,n)if(qz[i]!=qz[i-1]){
		//cnt[i-1], cnt[i]
		rep(j,1,cnt[i])printf("%d ",qz[i-2]+j%cnt[i-1]+1);
	}
	//printf("res = %d\n",res);
	ll ans=0;rep(i,1,n)ans+=1LL*i*cnt[i];assert(ans==s);
	//mid=res-1;assert(!solve(2,n-1,s-n,1));
	return 0;
}