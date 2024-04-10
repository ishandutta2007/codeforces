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

const int N = 1<<18|3;//4782969+3;
int n,cnt[N];char s[66][66];
ll f[N],dp[N][19],fac[20]; //ll deb;
map<Vi,ll>Map;
/*ll getans(Vi a){
	if(Map.count(a))return Map[a];
	ll res=0;
	static bool zt[19];int m=0;memset(zt,0,sizeof(zt));
	for(int x:a){rep(i,1,x-1)zt[++m]=1;m++;}
	static ll dp[N][19];int all=(1<<n)-1;memset(dp,0,sizeof(dp));//rep(i,0,all)dp[i]=0;
	rep(i,1,n)dp[1<<i-1][i]=1;
	rep(S,1,all)rep(i,1,n)if(dp[S][i]){
		if(zt[cnt[S]]){
			rep(x,1,n)if(!(S>>x-1&1)&&s[i][x]=='1')dp[S|(1<<x-1)][x]+=dp[S][i];
		}
		else{
			rep(x,1,n)if(!(S>>x-1&1))dp[S|(1<<x-1)][x]+=dp[S][i];
		}
	}
	rep(i,1,n)res+=dp[all][i];
	return Map[a]=res;
}*/
Vi c[6666];int sz;set<Vi>Set;int C[22][22],pos[22],id[N];
void ini(){//c[1..sz]
	rep(i,1,n)dp[1<<i-1][i]=1;
	c[0].resize(233);c[0][1]=-1;
	/*rep(i,1,sz){
		rep(j,1,n)printf("%d",c[i][j]);puts("");
	}*/
	int lst=0;
	rep(t,1,sz)rep(j,1,n-1)if(c[t][j]!=c[t-1][j]){
	//	rep(k,j,n)deb+=C[n][k];
		ll ans=0;
		int fro=min(j,lst+1);
		rep(ss,pos[fro+1],(1<<n)-1)rep(y,1,n)dp[id[ss]][y]=0;
		int mx=n;while(mx>j&&!c[t][mx])mx--;lst=mx;
	//	rep(ss,pos[j],(1<<n)-1){
		for(int ss=pos[fro];ss<=(1<<n)-1;ss++){
			int S=id[ss];
			if(cnt[S]>mx+1)break;
			if(cnt[S]==mx+1){rep(x,1,n)ans+=dp[S][x]*fac[n-cnt[S]];continue;}
			
			/*rep(i,1,n)if(dp[S][i]){
				if(c[t][cnt[S]]){
					rep(x,1,n)if(!(S>>x-1&1)&&s[i][x]=='1')dp[S|(1<<x-1)][x]+=dp[S][i];
				}
				else{
					rep(x,1,n)if(!(S>>x-1&1))dp[S|(1<<x-1)][x]+=dp[S][i];
				}
			}*/
			if(c[t][cnt[S]]){
				rep(x,1,n)if(!(S>>x-1&1))rep(i,1,n){
					dp[S|(1<<x-1)][x]+=dp[S][i]*(s[x][i]=='1');
				}
			}
			else{
				rep(x,1,n)if(!(S>>x-1&1))rep(i,1,n){
					dp[S|(1<<x-1)][x]+=dp[S][i];
				}
			}
			
		}
	//	ll ans=0;rep(x,1,n)ans+=dp[(1<<n)-1][x];
	//	printf("%d:%d %d %lld\n",t,j,pos[j],ans);
		Map[c[t]]=ans;
		break;
	}
}
bool cmp(int x, int y){return cnt[x]<cnt[y];}
int main() {
	rep(i,0,18){C[i][0]=C[i][i]=1;rep(j,1,i-1)C[i][j]=C[i-1][j-1]+C[i-1][j];}
	read(n);rep(i,1,1<<n)cnt[i]=cnt[i>>1]+(i&1);
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*i;
	rep(i,1,n)scanf("%s",s[i]+1);
	
	
	rep(i,0,(1<<n)-1)id[i]=i;
	sort(id,id+(1<<n),cmp);
	per(i,n,0)per(j,(1<<n)-1,0)if(cnt[id[j]]>=i)pos[i]=j;
	
	int all=(1<<n-1)-1;
	rep(i,0,all){
		Vi a;
		rep(l,1,n-1)if(i>>l-1&1){
			int r=l;while(r+1<=n-1&&(i>>r+1-1&1))r++;
			a.pb(r-l+2);l=r;
		}
		sort(ALL(a));
		reverse(ALL(a));
		static bool zt[19];int m=0;memset(zt,0,sizeof(zt));
		for(int x:a){rep(i,1,x-1)zt[++m]=1;m++;}
		Vi b={0};rep(j,1,n)b.pb(zt[j]);
		if(!Set.count(b))Set.insert(b),c[++sz]=b;
	//	f[i]=getans(a);
	}
	sort(c+1,c+sz+1);ini();
	rep(i,0,all){
		Vi a;
		rep(l,1,n-1)if(i>>l-1&1){
			int r=l;while(r+1<=n-1&&(i>>r+1-1&1))r++;
			a.pb(r-l+2);l=r;
		}
		sort(ALL(a));
		reverse(ALL(a));
		static bool zt[19];int m=0;memset(zt,0,sizeof(zt));
		for(int x:a){rep(i,1,x-1)zt[++m]=1;m++;}
		Vi b={0};rep(j,1,n)b.pb(zt[j]);
	//	if(!Set.count(b))Set.insert(b),c[++sz]=b;
		f[i]=Map[b];
	}
	
	
	rep(i,0,n-2)per(j,all,0)f[j]=j>>i&1?f[j]:f[j]-f[j^(1<<i)];
	rep(i,0,(1<<n-1)-1){
		printf("%lld ",f[i]);
	}
	return 0;
}