#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1<<20|3;
int n;char s[N],t[N];bool a[27][27];
bool ok[N];int ban[N],cnt[N],e[N];bool vis[23];
void dfs(int i){
	vis[i]=1;
	rep(j,0,n-1)if(a[i][j]||a[j][i])if(!vis[j])dfs(j);
}
int main() {
	rep(i,1,N-1)cnt[i]=cnt[i>>1]+(i&1);
	int T;read(T);while(T--){
		read(n);scanf("%s%s",s+1,t+1);
		memset(a,0,sizeof(a));
		int f[22],tot=0;memset(f,-1,sizeof(f));
		rep(i,1,n)if(s[i]!=t[i]&&-1==f[s[i]-'a'])f[s[i]-'a']=tot++;
		rep(i,1,n)if(s[i]!=t[i]&&-1==f[t[i]-'a'])f[t[i]-'a']=tot++;
		rep(i,1,n)if(s[i]!=t[i]){a[f[s[i]-'a']][f[t[i]-'a']]=1;}
		n=tot;
		rep(i,0,n-1){e[1<<i]=0;rep(j,0,n-1)e[1<<i]|=a[i][j]<<j;}
		rep(s,1,(1<<n)-1)ban[s]=ban[s^(s&-s)]|e[s&-s];
		rep(i,0,(1<<n))ok[i]=0;
		rep(i,1,n)ok[1<<i-1]=1;
		int res=0;
		rep(s,1,(1<<n)-1)if(ok[s]){
			umax(res,cnt[s]);
			rep(i,0,n-1)if((~ban[s]>>i&1)&&(~s>>i&1)){
				ok[s|1<<i]=1;
			//	printf("%d-->%d\n",s,i);
			}
		}
		int ori=res;
		res=2*n-res;
		rep(i,0,n)vis[i]=0;
		rep(i,0,n-1)if(!vis[i]){dfs(i);res--;}
		printf("%d\n",res);
	}
	return 0;
}