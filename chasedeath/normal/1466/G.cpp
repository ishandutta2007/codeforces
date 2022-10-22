#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e6+10,P=1e9+7;

int n,m,l,ma,P1[N],P2[N];
char s[N],t[N],str[N];

int fail[N],trie[N][26],cnt;
int val[N],c[N/10][26];
struct Query{
	int k,p,id;
	bool operator < (const Query __) const { return k<__.k; }
} Q[N];
int ans[N],dep[N];

struct Edge{
	int to,nxt;
} e[N];
int head[N];

int L[N],R[N],id[N],dfn;
void dfs(int u){
	id[L[u]=++dfn]=u;
	for(int i=head[u];i;i=e[i].nxt) dfs(e[i].to);
	R[u]=dfn;
}
void Build() {
	static queue <int> que;
	rep(i,0,25) if(trie[0][i]) que.push(trie[0][i]),dep[trie[0][i]]=1;
	while(!que.empty()) {
		int u=que.front(); que.pop();
		rep(i,0,25) {
			int &v=trie[u][i];
			if(!v) v=trie[fail[u]][i];
			else fail[v]=trie[fail[u]][i],que.push(v);
		}
	}
	rep(i,1,cnt) e[i]=(Edge){i,head[fail[i]]},head[fail[i]]=i;
	dfs(0);
}

struct BIT{
	int s[N];
	void Add(int p,int x){ 
		//cout<<"Add "<<p<<endl;
		while(p<=dfn) s[p]+=x,p+=p&-p; 
	}
	int Que(int p){
		int res=0;
		while(p) res+=s[p],p-=p&-p;
		return res;
	}
	int Que(int l,int r){ return Que(r)-Que(l-1); }
} T;

int sum[26];

int main(){
	n=rd(),m=rd(),scanf("%s%s",s+1,t+1),l=strlen(s+1);
	rep(i,1,m) {
		Q[i].k=rd(); scanf("%s",str+1);
		int u=0;
		for(int j=1;str[j];++j) {
			int &v=trie[u][str[j]-'a'];
			if(!v) v=++cnt,dep[v]=dep[u]+1;
			u=v,cmax(ma,j);
		}
		Q[i].p=u,Q[i].id=i;
	}
	Build(),sort(Q+1,Q+m+1);
	int p=1,i=1,u=0;
	rep(i,1,l) T.Add(L[u=trie[u][s[i]-'a']],1);

	int w=1,wi=1;
	for(i=0;i==0 || (i<=n && l<=ma && p<=m);++i) {
	//for(i=0;i<=n;++i) {
		if(i) {
			w=w*2%P,wi=((wi&1)?wi+P:wi)/2;
			s[l+1]=t[i],T.Add(L[u=trie[u][t[i]-'a']],1);
			rep(i,1,l) s[l+i+1]=s[i],T.Add(L[u=trie[u][s[i]-'a']],1);
			l=l*2+1;
		}
		//rep(i,1,l) cout<<s[i];
		//puts("");
		while(p<=m && Q[p].k<=i) ans[Q[p].id]=T.Que(L[Q[p].p],R[Q[p].p]),p++;
	}
	//cout<<"$"<<i<<endl;
	int twi=wi;
	if(p>m) goto Output;
	
	rep(ch,0,25) {
		int v=u;
		rep(i,0,cnt) val[i]=0;
		val[v=trie[v][ch]]++;
		int w=0;
		//if(ch==1) cout<<"add "<<v<<' '<<w<<endl;
		rep(i,1,l) {
			v=trie[v][s[i]-'a'],w=trie[w][s[i]-'a'];
			if(dep[v]<i) break;
			//if(ch==1) cout<<"add "<<v<<' '<<w<<endl;
			val[v]++,val[w]--;
		}
		drep(i,dfn,1) val[fail[id[i]]]+=val[id[i]];
		rep(i,p,m) c[i][ch]=val[Q[i].p];
	}
	for(;i<=n;++i) {
		w=w*2%P,wi=((wi&1)?wi+P:wi)/2;
		(sum[t[i]-'a']+=wi)%=P;
		while(p<=m && Q[p].k<=i) {
			ans[Q[p].id]=1ll*T.Que(L[Q[p].p],R[Q[p].p])*twi%P;
			//cout<<"$"<<Q[p].id<<' '<<1ll*ans[Q[p].id]*w%P<<' '<<c[p][1]<<endl;
			rep(i,0,25) ans[Q[p].id]=(ans[Q[p].id]+1ll*sum[i]*c[p][i])%P;
			ans[Q[p].id]=1ll*ans[Q[p].id]*w%P;
			p++;
		}
	}
	Output:;
	rep(i,1,m) printf("%d\n",ans[i]);
}