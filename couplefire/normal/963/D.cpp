#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<int> res[MAXN];

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
    void getAll(string &word){
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
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    string pat[n];
    int num[n];
    ACfixed ac;
    for(int i = 0; i<n; i++){
        int nn; cin >> nn;
        string ss; cin >> ss;
        num[i] = nn;
        pat[i] = ss;
        ac.add(ss, i);
    }
    ac.init();
    ac.getAll(s);
    for(int i = 0; i<n; i++){
        if(res[i].size() < num[i]){
            cout << -1 << endl;
            continue;
        }
        int ans = res[i][num[i]-1]-res[i][0]+pat[i].length();
        for(int j = 1; j+num[i]-1 < res[i].size(); j++){
            ans = min(ans, res[i][num[i]-1+j]-res[i][j]+(int)pat[i].length());
        }
        cout << ans << endl;
    }
    
}