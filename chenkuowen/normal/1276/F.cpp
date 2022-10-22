#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+5e5;
typedef long long ll;
int n;
char ss[MAX_N];
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y){
//		printf("[%d %d]",x,y);
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
namespace SAM{
	struct Node{
		int s[26],max,fa;
	}t[MAX_N*2];
	int last=1,top=1;
	int extend(int c){
		int x=++top,p=last;
		memset(t[x].s,0,sizeof(t[x].s));
		t[x].max=t[p].max+1;
		for(;p>0&&t[p].s[c]==0;p=t[p].fa)
			t[p].s[c]=x;
		if(p==0) t[x].fa=1;
		else{
			int d=t[p].s[c];
			if(t[d].max==t[p].max+1)
				t[x].fa=d;
			else{
				int q=++top;
				memcpy(t[q].s,t[d].s,sizeof(t[q].s));
				t[q].fa=t[d].fa,t[x].fa=q;
				t[d].fa=q,t[q].max=t[p].max+1;
				for(;p>0&&t[p].s[c]==d;p=t[p].fa)
					t[p].s[c]=q;
			}
		}
		last=x;
		return x;
	}
}
namespace STRING{
	int dep[MAX_N],dfn[MAX_N],ti=0;
	struct ST{
		int st[23][MAX_N*2],p[MAX_N*2];
		int merge(int x,int y){ return dep[x]<dep[y]?x:y; }
		inline int& operator[](int x){ return st[0][x]; }
		inline void build(int n){
			for(int l=1;l<=18;++l)
				for(int i=1;i<=n-(1<<l)+1;++i)
					st[l][i]=merge(st[l-1][i],st[l-1][i+(1<<l-1)]);
			p[1]=0; for(int i=2;i<=n;++i) p[i]=p[i>>1]+1;
		}
		int query(int x,int y){
			int l=p[y-x+1];
			return merge(st[l][x],st[l][y-(1<<l)+1]);
		}
	}st;
	void dfs(int x,int pre){
		dfn[x]=++ti; st[ti]=x; dep[x]=dep[pre]+1;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			dfs(y,x); st[++ti]=x;
		}
	}
	int pos[MAX_N],sa[MAX_N],r[MAX_N];
	vector<int> id[MAX_N];
	int lca(int x,int y){
		if(dfn[x]>dfn[y]) swap(x,y);
		return st.query(dfn[x],dfn[y]);
	}
	int lcp(int x,int y){
		if(x>n||y>n) return 0;
		return SAM::t[lca(pos[x],pos[y])].max;
	}
	bool cmp(int x,int y){
		int len=lcp(x,y);
		return ss[x+len]<ss[y+len];
	}
	void init(char* s){
		int n=strlen(s+1);
		for(int i=n;i>=1;--i){
			pos[i]=SAM::extend(s[i]-'a');
			id[pos[i]].push_back(i);
			sa[i]=i;
		}
		for(int i=2;i<=SAM::top;++i)
			G.add(SAM::t[i].fa,i);
		dfs(1,0);
		st.build(SAM::top+SAM::top-1);
		sort(sa+1,sa+n+1,cmp);
		for(int i=1;i<=n;++i) r[sa[i]]=i;
	}
}
int shift_width;
struct Cmp{
	inline bool operator()(int x,int y){
		return STRING::r[x+shift_width]<STRING::r[y+shift_width];
	}
};
struct Ot{
	int sw;
	multiset<int,Cmp> s;
	ll ans;
	Ot(){ sw=0,ans=0; }
	size_t size(){ return s.size(); }
	void change_width(int x){
		if(s.size()>0) ans-=x-sw;
		sw=x;
	}
	void insert(int x){
		shift_width=sw;
		ans+=n-x-sw+1;
		auto it=s.insert(x);
		auto it1=it==s.begin()?s.end():prev(it);
		auto it2=next(it);
		if(it1!=s.end()) ans-=STRING::lcp(x+sw,*it1+sw);
		if(it2!=s.end()) ans-=STRING::lcp(x+sw,*it2+sw);
		if(it1!=s.end()&&it2!=s.end())
			ans+=STRING::lcp(*it1+sw,*it2+sw);
	}
	void erase(int x){
		shift_width=sw;
		ans-=n-x-sw+1;
		auto it=s.lower_bound(x);
		auto it1=it==s.begin()?s.end():prev(it);
		auto it2=next(it);
		if(it1!=s.end()) ans+=STRING::lcp(x+sw,*it1+sw);
		if(it2!=s.end()) ans+=STRING::lcp(x+sw,*it2+sw);
		if(it1!=s.end()&&it2!=s.end())
			ans-=STRING::lcp(*it1+sw,*it2+sw);
		s.erase(it);
	}
	vector<int> dfs(){
		vector<int> ret;
		for(auto x:s) ret.push_back(x);
		return ret;
	}
};
Ot s[MAX_N];
ll dfs(int x,int pre){
	int pos=0; ll ret=0,ret1=0;
	vector<int> son;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		ret1+=dfs(y,x);
		ret++;
		son.push_back(y);
		if(s[pos].size()<=s[y].size()) pos=y;
		s[y].change_width(SAM::t[x].max+1);
	}
	if(son.size()>0) ++ret;
	for(auto y:son){
		if(y!=pos){
			vector<int> g=s[y].dfs();
			for(auto t:g)
				s[pos].insert(t);
		}
	}
	ret+=s[pos].ans;
	for(auto y:son){
		if(y!=pos){
			vector<int> g=s[y].dfs();
			for(auto t:g)
				s[pos].erase(t);
		}
	}
	s[pos].change_width(SAM::t[x].max);
	for(auto y:son){
		if(y!=pos){
			vector<int> g=s[y].dfs();
			for(auto t:g)
				s[pos].insert(t);
		}
	}
	for(auto t:STRING::id[x])
		s[pos].insert(t);
	swap(s[pos],s[x]);
	if(x!=1){
		int cnt=SAM::t[x].max-SAM::t[pre].max-1;
		ret+=s[x].ans*cnt+1ll*(cnt+1)*(cnt+2)/2-1;
	}
	return ret+ret1;
}
int main(){
	scanf("%s",ss+1);
	n=strlen(ss+1);
	STRING::init(ss);
	printf("%lld\n",dfs(1,0)+1);
	return 0;
}