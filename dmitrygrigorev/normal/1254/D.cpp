#include <bits/stdc++.h>
#define minus djsf
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 150007, LG = 20; //set it here

struct LA{

	int dv[LG][N];
	int n, m, u;
	int szlad = 0;
	vector<int> ladders[N], data[N];
	int what_ladder[N], what_number[N], logs[2*N], lengths[N];
	int fathers[N], d[N];

	void first_dfs(int vertex){
	    int l = 1;
	    for (int i=0; i < (int) data[vertex].size(); i++){
	        int to = data[vertex][i];
	        first_dfs(to);
	        l = max(l, lengths[to] + 1);
	    }
	    lengths[vertex] = l;
	}

	void up(int vertex, int ost){
	    if (vertex == 0 || ost == 0){
	        ladders[szlad-1].push_back(vertex);
	        return;
	    }
	    up(fathers[vertex], ost - 1);
	    ladders[szlad-1].push_back(vertex);
	}

	void binup_dfs(int vertex, int last){
	    if (last != -1){
	        dv[0][vertex] = last;
	        int nv = last;
	        int now_level = 1;
	        while (dv[now_level-1][nv] != -1){
	            dv[now_level][vertex] = dv[now_level-1][nv];
	            nv = dv[now_level-1][nv];
	            now_level++;
	        }
	    }
	    for (int i=0; i < (int) data[vertex].size(); i++){
	        binup_dfs(data[vertex][i], vertex);
	    }
	}

	void dfs(int vertex, int ladder, int depth){
	    d[vertex] = depth;
	    if (szlad == ladder){
	        szlad++;
	        up(vertex, lengths[vertex]);
	        what_ladder[vertex] = szlad - 1;
	        what_number[vertex] = ladders[szlad - 1].size() - 1;
	    }
	    else{
	        ladders[ladder].push_back(vertex);
	        what_ladder[vertex] = ladder;
	        what_number[vertex] = ladders[ladder].size() - 1;
	    }
	    bool go = false;
	    for (int i=0; i < (int) data[vertex].size(); i++){
	        int to = data[vertex][i];
	        if (go || lengths[to] + 1 != lengths[vertex]){
	            dfs(to, szlad, depth + 1);
	        }
	        else{
	            dfs(to, ladder, depth + 1);
	            go = true;
	        }
	    }
	}

	int get(int vertex, int when){
	    if (d[vertex] <= when) return 0;
	    if (when == 0) return vertex;
	    vertex = dv[logs[when]][vertex];
	    when -= (1LL << logs[when]);
	    return ladders[what_ladder[vertex]][what_number[vertex] - when];
	}
	 
	void pre_dfs(int vertex, int last){
		if (last != -1) fathers[vertex] = last;
	 
		int I = -1;
	 
		for (int i=0; i < data[vertex].size(); ++i){
			int to = data[vertex][i];
			if (to==last){
				I=i;
				continue;
			}
			pre_dfs(to, vertex);
		}
	 
		if (I!=-1){
			swap(data[vertex][I], data[vertex].back());
			data[vertex].pop_back();
		}
	}

	void init(vector<pair<int, int> > edges) {
		for (int i=0; i < edges.size(); ++i) {
			data[edges[i].first].push_back(edges[i].second);
			data[edges[i].second].push_back(edges[i].first);
		}

		pre_dfs(0, -1);
	    first_dfs(0);
	    int start = 0;
	    for (int i=0; i < LG; i++){
	        for (int j=0; j < N; j++){
	            dv[i][j] = -1;
	        }
	    }
	    for (int i=2; i <= 2*N; i*=2){
	        for (int j=i/2; j < i; j++){
	            logs[j] = start;
	        }
	        start++;
	    }
	    dfs(0, 0, 0);
	    binup_dfs(0, -1);

	}

};

vector<vector<int> > data;

LA la;
 
vector<int> sz, tin, tout, h;
 
int current = 0, n;
 
void dfs2(int vertex, int d, int last){
	int tut = 1;
	h[vertex] = d;
	tin[vertex] = current++;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		dfs2(to, d+1, vertex);
		tut += sz[to];
	}
	tout[vertex] = current++;
	sz[vertex] = tut;
}
 
const int mod = 998244353;
 
int pw(int x, int y){
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * pw(x, y-1)) % mod;
	int f = pw(x, y/2);
	return ((ll) f * f) % mod;
}
 
vector<int> minus;
 
int total_sum;
 
bool father(int u, int v){
	return ((tin[u] <= tin[v]) && (tout[u] >= tout[v]));
}
 
vector<int> was_added;
 
int RW;
 
void dfs3(int vertex, int kek, int last){
	minus[vertex] = (minus[vertex] + kek) % mod;
 
 
 
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		int sres = kek;
		if (was_added[vertex] != 0){
			int real = sz[to];
			real = ((ll) real * RW) % mod;
			real = ((ll) real * was_added[vertex]) % mod;
			sres = (sres + real) % mod;
		}
		if (was_added[to] != 0) {
			int real = n - sz[to];
			real = ((ll) real * RW) % mod;
			real = ((ll) real * was_added[to]) % mod;
			sres = (sres - real + mod) % mod;
		}
		dfs3(to, sres, vertex);
	}
 
}
 
void recalc(vector<pair<int, int> > adds){
	was_added.assign(n, 0);
	for (int i=0; i < adds.size(); ++i){
		int A = adds[i].first, B = adds[i].second;
		was_added[A] += B;
		was_added[A] %= mod;
	}
 
	int sres = 0, W=0;
	for (int j=0; j < adds.size(); ++j){
		int Q = adds[j].first, E = adds[j].second;
		if (Q==W) {
			continue;
		}
		if (father(Q, W)){
			int real = sz[la.get(W, h[W]-h[Q]-1)];
			real = ((ll) real * RW) % mod;
			real = ((ll) real * E) % mod;
			sres = (sres + real) % mod;
		}
		else{
			int real = n - sz[Q];
			real = ((ll) real * RW) % mod;
			real = ((ll) real * E) % mod;
			sres = (sres + real) % mod;
		}
	}
	
	dfs3(0, sres, -1);
 
}
 
signed main()
{
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("P_output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q;
    cin >> n >> q;
    data.assign(n, {});
    std::vector<pair<int, int> > ed;
    for (int i=0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        data[u].push_back(v);
        data[v].push_back(u);
        ed.push_back({u, v});
    }
    
    la.init(ed);

 
    int S = 500;
 
    sz.assign(n, -1), tin.assign(n, -1), tout.assign(n, -1), h.assign(n, -1);
    dfs2(0, 0, -1);
 
    int cur = 0;
 
    RW = pw(n, mod-2);
 
    minus.assign(n, 0);
 
    while (cur < q){
    	vector<pair<int, int> > adds;
    	for (int i=cur; i < cur+S && i < q; ++i){
    		int T;
    		cin >> T;
    		if (T==1) {
    			int v, d;
    			cin >> v >> d;
    			v--;
    			adds.push_back({v, d});
    			total_sum = (total_sum + d) % mod;
    		}
 
    		else{
    			int W;
    			cin >> W;
    			W--;
    			int sres = (total_sum - minus[W] + mod) % mod;
    			for (int j=0; j < adds.size(); ++j){
    				int Q = adds[j].first, E = adds[j].second;
    				if (Q==W) {
    					continue;
    				}
    				if (father(Q, W)){
    					int real = sz[la.get(W, h[W]-h[Q]-1)];
    					real = ((ll) real * RW) % mod;
    					real = ((ll) real * E) % mod;
    					sres = (sres - real + mod) % mod;
    				}
    				else{
						int real = n - sz[Q];
    					real = ((ll) real * RW) % mod;
    					real = ((ll) real * E) % mod;
    					sres = (sres - real + mod) % mod;
    				}
    			}
    			cout << sres << "\n";
    			continue;
    		}
    	}
    	cur += S;
    	recalc(adds);
    }
 
    
 
    }