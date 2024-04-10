#include <bits/stdc++.h>
using namespace std;
#define MAXN 400005

int n, m;
vector<int> adj[MAXN];
string arr[MAXN];
int ans[MAXN];
int add[MAXN];
vector<int> roots;
vector<int> need[MAXN];
int curcnt[MAXN];
int mp[MAXN];
vector<string> bruh;

struct ACfixed { // fixed alphabet
	static const int ASZ = 26;
	struct node { array<int,ASZ> to; int link = -1; int tlink = -1; int id = -1;};
	vector<node> d = {{}};
	int add(string s, int id) { // add word
		int v = 0;
		for(auto C:s) {
			int c = C-'a';
			if (!d[v].to[c]) d[v].to[c] = d.size(), d.emplace_back();
			v = d[v].to[c];
		}
        d[v].id = id;
		return v;
	}
	void init() { // generate links
		d[0].link = -1;
		queue<int> q; q.push(0);
		while (q.size()) {
			int v = q.front(); q.pop();
			for(int c = 0; c<ASZ; c++) {
				int u = d[v].to[c]; if (!u) continue;
				d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                d[u].tlink = (d[d[u].link].id == -1) ? d[d[u].link].tlink : d[u].link;
				q.push(u); 
			}
			if (v) for(int c = 0; c<ASZ; c++) if (!d[v].to[c]) 
				d[v].to[c] = d[d[v].link].to[c];
		}
	}
    vector<vector<int>> getAll(string word){
        vector<vector<int>> res(d.size(), vector<int>());
        int v = 0;
        for(int i = 0; i<word.length(); i++){
            v = d[v].to[word[i]-'a'];
            int cur = v;
            while(cur >= 0){
                if(d[cur].id != -1){
                    res[d[cur].id].push_back(i);
                }
                cur = d[cur].tlink;
            }
        }
        return res;
    }
} ac;

void dfs(int v1, int v2){
    v2 = ac.d[v2].to[add[v1]];
    int cur = v2;
    while(cur >= 0){
        if(ac.d[cur].id != -1) curcnt[ac.d[cur].id]++;
        cur = ac.d[cur].tlink;
    }
    for(auto x : need[v1]){
        ans[x] = curcnt[mp[x]];
    }
    for(auto u : adj[v1]){
        dfs(u, v2);
    }
    cur = v2;
    while(cur >= 0){
        if(ac.d[cur].id != -1) curcnt[ac.d[cur].id]--;
        cur = ac.d[cur].tlink;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int t; cin >> t;
        if(t == 1){
            char c; cin >> c;
            add[i] = c-'a';
            roots.push_back(i);
        }
        else{
            int j; char c; cin >> j >> c; --j;
            add[i] = c-'a';
            adj[j].push_back(i);
        }
    }
    cin >> m;
    for(int i = 0; i<m; i++){
        int j; cin >> j >> arr[i]; --j;
        need[j].push_back(i);
        bruh.push_back(arr[i]);
    }
    sort(bruh.begin(), bruh.end());
    bruh.erase(unique(bruh.begin(), bruh.end()), bruh.end());
    for(int i = 0; i<bruh.size(); i++) ac.add(bruh[i], i);
    for(int i = 0; i<m; i++){
        int p = lower_bound(bruh.begin(), bruh.end(), arr[i])-bruh.begin();
        mp[i] = p;
    }
    ac.init();
    // cout << ac.getAll("dada")[4].size() << endl;
    for(auto r : roots) dfs(r, 0);
    for(int i = 0; i<m; i++) cout << ans[i] << endl;
}