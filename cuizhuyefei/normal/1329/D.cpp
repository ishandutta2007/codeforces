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

const int N = 266666;
int n,pre[N],nxt[N],v[N];char s[N];set<int>Set[26];
vector<Pii>ans;
void mdy(int p, int x){while(p<=n)v[p]+=x,p+=p&-p;}
int qry(int p){int r=0;while(p)r+=v[p],p-=p&-p;return r;}
void ope(int x, int y){
//	printf("ope %d %d\n",x,y);
	int qian=pre[x],hou=nxt[y];
	ans.pb(mp(qry(x),qry(y)));
	Vi a;for(int i=x;;i=nxt[i]){a.pb(i);if(i==y)break;}
	for(int x:a)mdy(x,-1),pre[x]=nxt[x]=0;
	rep(i,0,25){
		auto it=Set[i].lower_bound(qian);
		while(it!=Set[i].end()&&(*it)<=y)it=Set[i].erase(it);
	}
	if(qian&&hou){
		nxt[qian]=hou;pre[hou]=qian;
		if(s[qian]==s[hou])Set[s[qian]-'a'].insert(qian);
	}
}
int main() {
	int T;read(T);while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		rep(i,0,25)Set[i].clear();ans.clear();
		rep(i,0,n)v[i]=0,nxt[i]=pre[i]=0;
		rep(i,1,n-1)if(s[i]==s[i+1])Set[s[i]-'a'].insert(i);
		rep(i,1,n-1)nxt[i]=i+1,pre[i+1]=i;
		rep(i,1,n)mdy(i,1);
		while(1){
			int mx=0,mx1=-1;
			rep(i,1,25)if(SZ(Set[i])){
				if(SZ(Set[i])>SZ(Set[mx]))mx1=mx,mx=i;
				else if(mx1==-1||SZ(Set[i])>SZ(Set[mx1]))mx1=i;
			}
		//	printf("qwq %d %d %d\n",mx,mx1,SZ(Set[mx]));
			if(mx1==-1||!SZ(Set[mx1])){
			//	for(int x:Set[mx])printf("%d ",x);puts("");
				Vi a;for(int x:Set[mx])a.pb(x);for(int x:a)ope(x,x);
				assert(qry(n));ans.pb(mp(1,qry(n)));
			//	cerr<<"OwO\n";
				break;
			}
			int x=*Set[mx].begin();
			int y=-1;rep(i,0,25)if(i!=s[x]-'a'&&SZ(Set[i])){
				auto it=Set[i].lower_bound(x);
				if(it!=Set[i].begin()){
					it--;if(y==-1||(*it)>y)y=*it;
				}
			}
			if(y!=-1){ope(nxt[y],x);continue;}
			y=-1;rep(i,0,25)if(i!=s[x]-'a'&&SZ(Set[i])){
				auto it=Set[i].upper_bound(x);
				if(it!=Set[i].end()&&(y==-1||(*it)<y)){
					y=*it;
				}
			}
			assert(~y);
			auto it=Set[mx].lower_bound(y);x=*(--it);
			ope(nxt[x],y);
		}
		printf("%d\n",SZ(ans));
		for(auto x:ans)printf("%d %d\n",x.fi,x.se);
	}
	return 0;
}