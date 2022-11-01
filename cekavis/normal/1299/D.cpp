#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, K = 5, S = 375, P = 1000000007;
int n, m, o, now, cnt, ans, cvis, a[K], s[2][S], b[1<<15], tr[S][1<<K], sum[S][S], f[N], g[N], p[N], vis[N];
bool in[N];
vector<pair<int,int>> e[N];
struct wish{
	int o, a[K];
	wish(){ memset(a, o=0, sizeof a);}
	void insert(int x){
		for(int i=K; i--;) if(x>>i&1){
			if(!a[i]){
				for(int j=i; j--;) if(x>>j&1) x^=a[j];
				for(int j=i+1; j<K; ++j) if(a[j]>>i&1) a[j]^=x;
				a[i]=x;
				return;
			}
			else x^=a[i];
		}
		o=1;
	}
	void print(){
		puts("-----");
		for(int i=K; i--;){
			for(int j=0; j<K-i-1; ++j) putchar(' ');
			for(int j=i+1; j--;) putchar('0'+(a[i]>>j&1));
			puts("");
		}
		puts("-----");
	}
	wish operator+(const wish &y)const{
		wish ans=y;
		for(int i=0; i<K; ++i) if(a[i]) ans.insert(a[i]);
		return ans;
	}
	wish operator^(const int x)const{
		wish ans=*this;
		ans.insert(x);
		return ans;
	}
	int id(){
		if(o) return 0;
		int x=0;
		for(int i=K; i--;) (x<<=i+1)|=a[i];
		return b[x];
	}
} c[S];
void dfs(int u, int fa=0){
	// printf("dfs: %d\n", u);
	vis[u]=++cvis;
	for(auto [v, w]:e[u]) if(!in[v] || v==now){
		if(!vis[v]) g[v]=g[u]^w, dfs(v, u);
		else if(v!=fa && vis[v]<vis[u]) f[now]=tr[f[now]][g[u]^w^g[v]];//, printf("insert: %d %d %d\n", u, v, g[u]^w^g[v]);
	}
}
int main() {
	// f[1].insert(8), f[1].insert(9), f[1].insert(10);
	// printf("%d\n", f[1].o);
	// return 0;
	for(int i=1; i<K; ++i) a[i]=a[i-1]+i+1;
	for(int i=0; i<1<<15; ++i){
		for(int j=0; j<K; ++j) for(int k=1; k<=j; ++k){
			if(!(i>>a[j]&1) && (i>>(a[j]-k)&1)) goto skip;
			if((i>>(a[j]-k)&1) && (i>>a[j-k]&1)) goto skip;
		}
		b[i]=++cnt;
		for(int j=0, x=i; j<K; ++j) c[cnt].a[j]=x&((1<<(j+1))-1), x>>=j+1;
		// c[cnt].print(), printf(">> %d\n", i);
		// assert(c[cnt].id()==cnt);
		skip:;
	}
	// printf("cnt: %d\n", cnt);
	for(int i=1; i<=cnt; ++i) for(int j=i; j<=cnt; ++j)
		sum[j][i]=sum[i][j]=(c[i]+c[j]).id();
	for(int i=1; i<=cnt; ++i) for(int j=0; j<1<<K; ++j) tr[i][j]=(c[i]^j).id();

	scanf("%d%d", &n, &m);
	for(int i=1, x, y, z; i<=m; ++i){
		scanf("%d%d%d", &x, &y, &z),
		e[x].emplace_back(y, z), e[y].emplace_back(x, z);
	// 	if(i>50) printf("%d %d %d\n", x, y, z);
	}
	in[1]=1;
	for(auto [i, j]:e[1]) in[i]=1, p[i]=j;
	s[o][1]=1;
	for(int i=2; i<=n; ++i) if(in[i]){
		f[i]=1, dfs(now=i);
		int x=0, y=0, z;
		for(auto &j:e[i]) if(j.first!=1 && in[j.first]) x=j.first, y=j.second;
		memcpy(s[o^1], s[o], sizeof *s);
		if(!x){
			// printf(">> %d\n", f[i]);
			for(int j=0; j<=cnt; ++j) (s[o^1][sum[j][f[i]]]+=s[o][j])%=P;
		}
		else if(x<i){
			z=sum[f[x]][f[i]];
			// printf(">> %d\n", z);
			for(int j=0; j<=cnt; ++j) (s[o^1][sum[j][z]]+=s[o][j]*2%P)%=P;
			z=tr[z][p[x]^p[i]^y];
			// printf("-- %d\n", sum[z][z]);
			for(int j=0; j<=cnt; ++j) (s[o^1][sum[j][z]]+=s[o][j])%=P;
		}
		o^=1;
	}
	for(int i=1; i<=cnt; ++i) (ans+=s[o][i])%=P;
	printf("%d\n", ans);
	return 0;
}