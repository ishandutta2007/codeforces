#include<iostream>
#include<vector>
#include<string.h>
#include<assert.h>

using namespace std;
#define ll long long

const int N = 205, M = 30;
struct two_sat{
	int id, top, cnt, stk[N*2], dfn[N*2], low[N*2], bl[N*2];
	bool ans[N], instk[N*2];
	vector<int> e[N*2];
	void add(int x, int y){ e[x].push_back(y);}
	void tarjan(int u){
		dfn[u]=low[u]=++cnt;
		instk[stk[++top]=u]=1;
		for(int v:e[u])
			if(!dfn[v]) tarjan(v), low[u]=min(low[u], low[v]);
			else if(instk[v]) low[u]=min(low[u], dfn[v]);
		if(low[u]==dfn[u]){
			++id;
			do instk[stk[top]]=0, bl[stk[top]]=id; while(stk[top--]!=u);
		}
	}
	bool Solve(int n){
		id=top=cnt=0, memset(dfn+1, 0, n<<3);
		for(int i=1; i<=n<<1; ++i) if(!dfn[i]) tarjan(i);
		// for(int i=1; i<=n<<1; ++i) e[i].clear();
		for(int i=1; i<=n; ++i) if(bl[i]==bl[i+n]) return 0;
		for(int i=1; i<=n; ++i) ans[i]=bl[i]<bl[i+n];
		return 1;
	}
	bool &operator[](int x){ return ans[x];}
} wish;
int n, m, c;
char l[M], s[N];
int main() {
	cin>>l>>n>>m, c=strlen(l);
	bool same=1;
	for(int i=1; i<c; ++i) same&=l[i]==l[i-1];
	for(int i=1; i<=m; ++i){
		int pos1, pos2;
		char t1, t2;
		cin>>pos1>>t1>>pos2>>t2;
		if(same && t1==l[0] && t2!=l[0]) return puts("-1"), 0;
		wish.add(pos1+(t1=='C')*n, pos2+(t2=='C')*n);
		wish.add(pos2+(t2!='C')*n, pos1+(t1!='C')*n);
	}
	cin>>(s+1);
	int i=n;
	for(; i; --i){
		bool vis[2]={0};
		for(int j=s[i]-'a'+(i<n); j<c; ++j) if(!vis[l[j]=='C']){
			vis[l[j]=='C']=1;
			for(int k=1; k<i; ++k)
				if(l[s[k]-'a']=='C') wish.add(k, k+n); else wish.add(k+n, k);
			if(l[j]=='C') wish.add(i, i+n); else wish.add(i+n, i);
			bool t=wish.Solve(n);
			wish.e[i+(l[j]!='C')*n].pop_back();
			for(int k=1; k<i; ++k) wish.e[k+(l[s[k]-'a']!='C')*n].pop_back();
			if(t){
				s[i]=j+'a';
				goto nxt;
			}
		}
	}
	return puts("-1"), 0;
	nxt:;
	while(++i<=n){
		bool vis[2]={0};
		assert(!vis[0] && !vis[1]);
		for(int j=0; j<c; ++j) if(!vis[l[j]=='C']){
			vis[l[j]=='C']=1;
			for(int k=1; k<i; ++k)
				if(l[s[k]-'a']=='C') wish.add(k, k+n); else wish.add(k+n, k);
			if(l[j]=='C') wish.add(i, i+n); else wish.add(i+n, i);
			bool t=wish.Solve(n);
			wish.e[i+(l[j]!='C')*n].pop_back();
			for(int k=1; k<i; ++k) wish.e[k+(l[s[k]-'a']!='C')*n].pop_back();
			if(t){
				s[i]=j+'a';
				break;
			}
		}
	}
	puts(s+1);
	return 0;
}