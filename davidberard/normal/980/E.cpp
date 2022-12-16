// David Berard
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int ROOT = 1;
int N, K;

vector<vector<int>> lca;
vector<int> par;
vector<int> level;
vector<bool> included;
int st_root; //subtree root

void build_lca() {
	lca = vector<vector<int>>(par.size(), vector<int>(21, -1));
	for(size_t i=0;i<par.size();++i) {
		lca[i][0] = par[i];
	}
	for(int p=0;p<20;++p) {
		for(size_t i=0;i<par.size();++i) {
			lca[i][p+1] = (lca[i][p] == -1 ? -1 : lca[lca[i][p]][p]);
		}
	}
}

inline int get_nth_parent(int u, int num) {
	for(int i=0;i<21 && num;++i) {
		if(num&(1<<i)) {
			u = lca[u][i];
			num ^= (1<<i);
		}
    }
    return u;
}

inline int get_lca(int u, int v) {
    if(level[u] > level[v]) {
        swap(u, v);
    }
    v = get_nth_parent(v, level[v]-level[u]);
    for(int i=20;i>=0;--i) {
        if(lca[u][i] != lca[v][i]) {
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    if(u!=v) {
        u = lca[u][0];
        v = lca[v][0];
    }
	return u;
}

inline int get_lca_dist(const int& u, const int& v) {
	int l = get_lca(u, v);
    return level[u]+level[v]-2*level[l];
}

inline int add_with_new_root(const int& u) {
	int l = get_lca(st_root, u);
	int amt = 0;
	for(int v=par[st_root];v!=l;v=par[v]) {
		included[v] = true;
		++ amt;
	}
	for(int v=u;v!=l;v=par[v]) {
		included[v] = true;
		++ amt;
	}
	++amt;
	included[l] = true;
	st_root = l;
	return amt;
}

// when u is in the subtree rooted at st_root
inline int get_dist_in_subtree(int u, bool add) {
    int ans = 0;
	if(!add) {
		for(int i=21;i>=0;--i) {
			if(level[u]-(1<<i) < level[st_root]) {
				continue;
			}
			if(!included[lca[u][i]]) {
				u = lca[u][i];
				ans += (1<<i);
			}
		}
		if(!included[u]) {
			++ans;
		}
	}
	else {
		for(int v=u;!included[v];v=par[v]) {
			included[v] = true;
			++ans;
		}
	}
    return ans;
}

inline int get_dist(const int& u, bool add = false) { // get distance to the existing subtree, in # of additional edges
    if(level[u] >= level[st_root]) {
		//////cerr << " CALL WITH " << u << ", " << st_root << " -> " << level[u] - level[st_root] << endl;
        int upar = get_nth_parent(u, level[u]-level[st_root]);
        if(upar == st_root) {
            //this is the slow one
			////cerr << "!!" << endl;
            return get_dist_in_subtree(u, add);
        } else {
            // this adsd another st root
			if(add) {
				return add_with_new_root(u);
			} else {
				return get_lca_dist(u, st_root);
			}
        }
    } else {
        // easy: obviously, this adds a new st root
		if(add) {
			return add_with_new_root(u);
		} else {
			return get_lca_dist(u, st_root);
		}
    }
}

vector<vector<int>> edges;

void dfs(const int& u, const int& mpar, const int& lvl) {
	//////cerr << "  PASS " << u << endl;
	par[u] = mpar;
    level[u] = lvl;
	for(int v : edges[u]) {
		if(v != mpar) {
			dfs(v, u, lvl+1);
		}
	}
}

inline char get() {
	static char buf[100000], *S = buf, *T = buf;
	if(S==T) {
		T = (S=buf)+fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}

inline void read(int& x) {
	static char c;
	x = 0;
	for(c=get();c < '0' || c > '9';c=get());
	for(;c >='0' && c <='9';c=get()) x = x*10-'0'+c;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	read(N);
	read(K);
	edges.resize(N+1);
	par = vector<int>(N+1, -1);
	level = vector<int>(N+1, -1);
	included = vector<bool>(N+1, false);
	for(int i=0;i<N-1;++i) {
		int a, b;
		read(a);
		read(b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(ROOT, -1, 0);
	build_lca();

	int used = 1;
	st_root = N;
	included[N] = true;
	for(int i=N-1;i>0 && used < N-K;--i) {
		int predicted_dist = get_dist(i);
		//cerr << "Predicted dist to " << i << ": " << predicted_dist << ", stroot = " << st_root << endl;
		if(predicted_dist+used <= N-K) {
			//assert(get_dist(i, true) == predicted_dist);
			//cerr << " TAKE " << i << endl;
			get_dist(i, true);
			used += predicted_dist;
		}
	}

	for(int i=1;i<=N;++i) {
		if(!included[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	
	return 0;
}