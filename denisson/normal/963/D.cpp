#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

string s;
int n;
int ans[100007];

int pi[200007];
char f[200007];

void prefix_function (int n) {
	pi[0] = 0;
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && f[i] != f[j])
			j = pi[j-1];
		if (f[i] == f[j])  ++j;
		pi[i] = j;
	}
}

struct vert{
	int to[26];
	int d;
	vert() { for (int i = 0; i < 26; i++) to[i] = -1; d = -1; }
};

int sz = 1;
vert w[100007];

int need[100007];

void add(string &s, int type){
	int v = 0;
	for (char c : s){
		if (w[v].to[c - 'a'] == -1) w[v].to[c - 'a'] = sz++;
		v = w[v].to[c - 'a'];
	}
	w[v].d = type;
}

vector<int> save[100007];
int ww[100007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> n;
    for (int i = 0; i < n; i++){
    	int k;
    	string t;
    	cin >> k >> t;
    	if (t.size() > 300){
    		int dd = 0;
    		for (int j = 0; j < t.size(); j++) f[dd++] = t[j];
    		f[dd++] = '$';
    		for (int j = 0; j < s.size(); j++) f[dd++] = s[j];
    		prefix_function(dd);
    		vector<int> g;
    		for (int j = t.size() + 1; j < dd; j++){
    			if (pi[j] == t.size()) g.pb(j);
    		}
    		int now = s.size() + 1;

    		for (int j = 0; j + k - 1 < g.size(); j++){
    			now = min(now, g[j + k - 1] - g[j] + (int)t.size());
    		}

    		if (now == s.size() + 1) now = -1;
    		ans[i] = now;
    	} else {
    		need[i] = k;
    		reverse(all(t));
    		add(t, i);
    		ans[i] = -1;
    		ww[i] = t.size();
    	}
    }

    for (int i = 0; i < s.size(); i++){
    	int v = 0;
    	for (int j = i; j >= 0; j--){
    		v = w[v].to[s[j] - 'a'];
    		if (v == -1) break;
    		if (w[v].d != -1) save[w[v].d].pb(i);
    	}
    }

    for (int i = 0; i < n; i++) if (save[i].size()){
    	int now = s.size() + 1;

    	for (int j = 0; j + need[i] - 1 < save[i].size(); j++){
    		now = min(now, save[i][j + need[i] - 1] - save[i][j] + ww[i]);
    	}

    	if (now == s.size() + 1) now = -1;
    	ans[i] = now;
    }


    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}