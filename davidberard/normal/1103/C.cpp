#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int NMAX = 250250;

int N, M, K;

vector<int> edges[NMAX];
int depth[NMAX];
int par[NMAX];

vector<int> leaves;

pii maxdepth;

void dfs(int u, int p, int d) {
	maxdepth = max(maxdepth, pii(d, u));
	par[u] = p;
	depth[u] = d;
	int ch = 0;
	for(auto& v : edges[u]) {
		if(!depth[v]) {
			dfs(v, u, d+1);
			ch++;
		}
	}
	if(!ch) leaves.push_back(u);
}

inline char get() {
	static char buf[1000000], *S=buf, *T=buf;
	if(S == T) {
		T = (S=buf) + fread(buf, 1, 1000000, stdin);
		if(S == T) return EOF;
	}
	return *S++;
}

inline void read(int& x) {
	static char c; x = 0;
	for(c=get();c<'0' || c>'9';c=get());
	for(;c>='0' && c<='9';c=get()) x = x*10+c-'0';
}

inline void wch(char c) {
	const int sz = 1000000;
	static char buf[sz], *S=buf, *T=buf+sz-1;
	if(c == EOF) goto wflush;
	//cerr << " writing " << c << endl;
	*S++ = c;
	if(S==T) {
wflush:
		//cerr << " flushing " << endl;
		fwrite(buf, 1, S-buf, stdout);
		S=buf;
	}
}

inline void write(const char* s) {
	while(*s != 0) {
		wch(*s++);
	}
}

inline void write(int x) {
	static char buf[20];
	int i;
	for(i=0;x;x/=10,++i) {
		buf[i]=x%10;
	}
	while(i) {
		wch(buf[--i]+'0');
	}
}

int main () {
	ios_base::sync_with_stdio(0), cin.tie(0);
	read(N);
	read(M);
	read(K);
	for(int i=0;i<M;++i) {
		int u, v;
		read(u);
		read(v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1, 0, 1);
	if(maxdepth.first-1 > ((N+K-1)/K)) {
		vector<int> p;
		p.push_back(maxdepth.second);
		while(p.size() <= ((N+K-1)/K)) {
			p.push_back(par[p.back()]);
		}
		write("PATH\n");
		write(p.size());
		write("\n");
		for(auto& x : p) {
			write(x);
			write(" ");
		}
		write("\n");
		wch(EOF);
		return 0;
	}
	
	vector<vector<int>> cycles;
	for(int i=0;i<K;++i) {
		int u = leaves[i];
		priority_queue<int, vector<int>, greater<int>> pq;
		for(int v : edges[u]) {
			if(depth[v] == depth[u]-1) continue;
			pq.push(v);
			if(pq.size() > 2) pq.pop();
		}
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		cycles.push_back(vector<int>());
		if(depth[y] > depth[x]) swap(x, y);
		if((depth[u]-depth[x]+1)%3 != 0) {
			cycles.back().push_back(u);
			while(cycles.back().back() != x) {
				cycles.back().push_back(par[cycles.back().back()]);
			}
		}
		else if((depth[u]-depth[y]+1)%3 != 0) {
			cycles.back().push_back(u);
			while(cycles.back().back() != y) {
				cycles.back().push_back(par[cycles.back().back()]);
			}
		} else {
			assert(depth[x] > depth[y]);
			assert((depth[x]-depth[y]+2)%3 != 0);
			cycles.back().push_back(u);
			cycles.back().push_back(x);
			while(cycles.back().back() != y) {
				cycles.back().push_back(par[cycles.back().back()]);
			}
		}
	}
	write("CYCLES\n");
	for(auto& v : cycles) {
		write(v.size());
		write("\n");
		for(auto& x : v) {
			write(x);
			write(" ");
		}
		write("\n");
	}
	wch(EOF);
	
	return 0;
}