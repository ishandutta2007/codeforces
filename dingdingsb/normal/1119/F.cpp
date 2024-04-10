#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
const int N=3e5+10;
mt19937 myrnd(random_device{}());
namespace fhq{
	// 
	struct node{
		int sz,rnd,val;
		node(){rnd=myrnd();}
		int lc,rc;ll sum;
	}t[N];
	int cnt;
	int newnode(int x){++cnt;t[cnt].val=t[cnt].sum=x;t[cnt].sz=1;return cnt;}
	void pushup(int x){
		t[x].sz=t[t[x].lc].sz+1+t[t[x].rc].sz;
		t[x].sum=t[t[x].lc].sum+t[x].val+t[t[x].rc].sum;
	}
	void split(int x,int k,int&a,int&b){
		if(!x)return a=b=0,void();
		if(t[t[x].lc].sz+1<=k)a=x,split(t[x].rc,k-t[t[x].lc].sz-1,t[x].rc,b);
		else b=x,split(t[x].lc,k,a,t[x].lc);
		pushup(x);
	}
	void splitv(int x,int v,int&a,int&b){
		if(!x)return a=b=0,void();
		if(t[x].val>=v)a=x,splitv(t[x].rc,v,t[x].rc,b);
		else b=x,splitv(t[x].lc,v,a,t[x].lc);
		pushup(x);
	}
	int merge(int x,int y){
		if(!x||!y)return x+y;
		if(t[x].rnd<t[y].rnd){
			t[x].rc=merge(t[x].rc,y);
			pushup(x);return x;
		}else{
			t[y].lc=merge(x,t[y].lc);
			pushup(y);return y;
		}
	}
	vector<int>arr;
	void dfs(int u){
		if(!u)return;
		arr.pb(t[u].val);
		dfs(t[u].lc);
		dfs(t[u].rc);
	}
	struct fhqtreap{
		int rt,sz;
		void ins(int x){
			sz++;int a,b;
			splitv(rt,x,a,b);
			rt=merge(merge(a,newnode(x)),b);
		}
		ll kthsum(int k){
			//k
			chkmn(k,sz);
			int a,b;
			split(rt,k,a,b);
			ll res=t[a].sum;
			rt=merge(a,b);
			return res;
		}
		vector<int>tovec(){
			arr.clear();
			dfs(rt);
			return arr;
		}
	};
}
int n,k;set<pair<int,int>>e[N];
ll dp[N][2];int deg[N];
fhq::fhqtreap t[N];
set<int>now;vector<int>ids[N];
ll sum,tag;bool vis[N];
void dfs(int u){
	dp[u][0]=dp[u][1]=-0x3f3f3f3f3f3f3f3f;
	vis[u]=1;
	ll res=0;
	vector<ll>arr;
	for(auto E:e[u]){
		int v,w;tie(v,w)=E;
		if(vis[v])continue;
		dfs(v);
		res+=dp[v][0];
		arr.pb(dp[v][1]+w-dp[v][0]);
	}
	sort(arr.begin(),arr.end());
	reverse(arr.begin(),arr.end());
	ll now=0;
	for(int i=0;i<=k;i++){
		chkmx(dp[u][0],res+now+t[u].kthsum(k-i));
		if(i==(int)arr.size())break;
		now+=arr[i];
	}
	now=0;
	for(int i=0;i<k;i++){
		chkmx(dp[u][1],res+now+t[u].kthsum(k-i-1));
		if(i==(int)arr.size())break;
		now+=arr[i];
	}
}
signed main(){
	read(n);
	for(int i=1,u,v,w;i<n;i++)
		read(u,v,w),
		e[u].insert(mp(v,w)),e[v].insert(mp(u,w)),deg[u]++,deg[v]++,sum+=w;
	for(int i=1;i<=n;i++)ids[deg[i]].pb(i),now.insert(i);
	write(sum),pc(' ');
	for(k=1;k<n;k++){
		// k 
		for(auto i:ids[k]){
			now.erase(i);
			auto has=t[i].tovec();
			for(auto x:has)tag+=x;
			for(auto E:e[i]){
				int j,w;tie(j,w)=E;
				e[j].erase(mp(i,w));
				t[j].ins(w);
			}
		}
		ll res=0;
		for(auto i:now)vis[i]=0;
		for(auto i:now)if(!vis[i])dfs(i),res+=dp[i][0];
		write(sum-res-tag);pc(' ');
	}
}