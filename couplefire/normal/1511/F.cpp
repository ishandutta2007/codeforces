#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

using ll = long long;

const int N = 162;
using mat = array<array<int, N>, N>;


const int maxn = 1e6 + 5;

const int mod = 998244353;

struct node {
    int nxt[26];
    bool term;
    node() {
	memset(nxt, -1, sizeof(nxt));
	term = false;
    }
    int& operator[](const int i) {
	return nxt[i];
    }
};


vector<node> trie;

void add(string s) {
    int at = 0;
    for (char d: s) {
	int c = int(d-'a');
	if (trie[at][c] == -1) {
	    int ptr = trie.size();
	    trie.push_back(node());
	    trie[at][c] = ptr;
	}
	at = trie[at][c];
    }
    trie[at].term = true;
}

queue<pair<int,int>> Q; //(u,v)
map<pair<int,int>, int> ord;

int get(int u, int v) {
    if (u > v) {
	swap(u, v);
    }
    if (!ord.count({u,v})) {
	ord[{u,v}] = ord.size();
	Q.push({u, v});
    }
    return ord[{u,v}];
}



int add(int x, int y) {
    x += y;
    if (x >= mod) x %= mod;
    return x;
}

int mul(int x, int y) {
    ll res = 1ll*x*y;
    res %= mod;
    return res;
}

mat operator*(const mat& a, const mat& b) {
    mat c;
    for (int i=0; i<N; i++) {
	for (int j=0; j<N; j++) {
	    c[i][j] = 0;
	}
    }

    for (int i=0; i<N; i++) {
	for (int j=0; j<N; j++) {
	    for (int k=0; k<N; k++) {
		c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	    }
	}
    }
    
    return c;
}

mat matpw(mat g, int p) {
    mat res;
    for (int i=0; i<N; i++) {
	res[i][i] = 1;
    }
    
    while (p>0) {
	if (p&1) {
	    res = res * g;
	}
	g = g*g;
	p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n, m;
    cin>>n>>m;
    
    trie.push_back(node());
    for (int i=0; i<n; i++) {
	string s;
	cin>>s;
	add(s);
    }

        
    mat g;
    for (int i=0; i<N; i++) {
	for (int j=0; j<N; j++) {
	    g[i][j] = 0;
	}
    }

    ord[{0,0}] = 0;
    Q.push({0,0});


    while (Q.size()) {
	auto cur = Q.front();
	Q.pop();
	int u = cur.first;
	int v = cur.second;
	int at = get(u, v);
	for (int c=0; c<26; c++) {
	    int tou = trie[u][c];
	    int tov = trie[v][c];
	    if (tou==-1 || tov==-1) {
		continue;
	    }
	    g[at][get(tou,tov)]++;
	    if (trie[tou].term) {
		g[at][get(0, tov)]++;
	    }
	    if (trie[tov].term) {
		g[at][get(tou, 0)]++;
	    }
	    if (trie[tou].term && trie[tov].term) {
		g[at][0]++;
	    }
	}
    }

    g = matpw(g, m);
    cout<<g[0][0]<<endl;
    
    return 0;
}