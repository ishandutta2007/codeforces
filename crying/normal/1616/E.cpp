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
const ll MAXN=1e5+10,INF=1e18;
int T,n;
int nxt[MAXN],cur[200];
map<char,int>pos;
ll ans=INF;
char s[MAXN],t[MAXN];
struct BIT{
	int t[MAXN];
	void clr(){
		rep(i,1,n)t[i]=0;
	}
	void upd(int x,int v){
		for(;x<=n;x+=lowbit(x))t[x]+=v;
	}
	int qry(int x){
		int sum=0;for(;x;x-=lowbit(x))sum+=t[x];return sum;
	}
}bit;
void solve(){
	scanf("%d%s%s",&n,s+1,t+1);
	pos.clear();
	per(i,n,1){
		nxt[i]=pos[s[i]];
		pos[s[i]]=i; 
	} 
	rep(i,'a','z')cur[i]=pos[i];
	ans=INF;
	ll ret=0;
	rep(i,1,n){
		rep(j,1,t[i]-1){
			if(cur[j]==0)continue;
		//	printf("j:%c %d\n",j,cur[j]);
			ans=min(ans,ret+(cur[j]+bit.qry(cur[j])-i));
		}
		if(cur[t[i]]==0)break;
		ret+=(cur[t[i]]+bit.qry(cur[t[i]])-i);
		//printf("i:%d ret:%lld\n",i,ret);
		bit.upd(1,1);
		bit.upd(cur[t[i]],-1);
		cur[t[i]]=nxt[cur[t[i]]];
	}
	bit.clr();
	if((string)(t+1)>(string)(s+1)){
		printf("0\n");return;
	}
	if(ans==INF)printf("-1\n");
	else printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}