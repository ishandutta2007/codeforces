#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

struct ACfixed { // fixed alphabet
	static const int ASZ = 10;
	struct node { array<int,ASZ> to; int link = -1; int tlink = -1; int id = -1;};
	vector<node> d = {{}};
	int add(string s, int id) { // add word
		int v = 0;
		for(auto C:s) {
			int c = C-'0';
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
    vector<vector<int>> getAll(string &word){
        vector<vector<int>> res(d.size(), vector<int>());
        int v = 0;
        for(int i = 0; i<word.length(); i++){
            v = d[v].to[word[i]-'0'];
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
};

vector<string> arr;
int n, x;
string s;
string curstr = "";
ACfixed ac;

void gen(int cur){
    if(cur == 0){
        arr.push_back(curstr);
        return;
    }
    for(int i = 1; i<=9; i++){
        if(i > cur) continue;
        curstr.push_back('0'+i);
        int csum = 0;
        bool work = true;
        for(int j = curstr.size()-1; j>=0; j--){
            csum += curstr[j]-'0';
            if(csum != x && x%csum == 0){
                work = false;
                break;
            }
        }
        if(work) gen(cur-i);
        curstr.pop_back();
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> x;
    n = s.length();
    gen(x);
    for(int i = 0; i<arr.size(); i++) ac.add(arr[i], i);
    ac.init();
    vector<int> dp(ac.d.size(), INF);
    dp[0] = 0;
    for(auto ch: s){
        vector<int> nextdp(ac.d.size(), INF);
        for(int state = 0; state < ac.d.size(); state++){
            if(dp[state] == INF) continue;
            nextdp[state] = min(nextdp[state], dp[state]+1);
            int trans = ac.d[state].to[ch-'0'];
            if(ac.d[trans].id == -1) nextdp[trans] = min(nextdp[trans], dp[state]);
        }
        swap(dp, nextdp);
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
}