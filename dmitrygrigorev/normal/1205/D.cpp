#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > data;
int n;
bool res;
int dfs(int vertex, int last){
	int l = 1;
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (to==last) continue;
		int S = dfs(to, vertex);
		if (S > n/2) res = false;
		l += S;
	}
	return l;
}
vector<int> cmp;
void dfs2(int vertex, int last){
	cmp.push_back(vertex);
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (to==last) continue;
		dfs2(to, vertex);
	}
}
bool cmp2(vector<int> &a, vector<int> &b){
	return (a.size() > b.size());
}
int ss=1, bb=1, M;
void dfs3(int vertex, int last, int given, bool is_small){
	if (is_small){
		int old=ss;
		if (last != -1){
			cout << vertex+1 << " " << last+1 << " " << ss-given << endl;
			ss++;
		}
		for (int i=0; i < data[vertex].size(); i++){
			int to = data[vertex][i];
			if (to==last) continue;
			dfs3(to, vertex, old, is_small);
		}
	}
	else{
		int old=bb;
		if (last != -1){
			cout << vertex+1 << " " << last+1 << " " << (bb-given)*M << endl;
			bb++;
		}
		for (int i=0; i < data[vertex].size(); i++){
			int to = data[vertex][i];
			if (to==last) continue;
			dfs3(to, vertex, old, is_small);
		}
	}
}
signed main() {
	#ifdef LOCAL
		freopen("H_input.txt", "r", stdin);
		//freopen("C_output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> n;
   	data.assign(n, {});
   	for (int i=0; i < n-1; i++){
   		int u, v;
   		cin >> u >> v;
   		u--, v--;
   		data[u].push_back(v);
   		data[v].push_back(u);
   	}
   	int centr = -1;
   	for (int i=0; i < n; i++){
   		res = true;
   		dfs(i, -1);
   		if (res){
   			centr = i;
   			break;
   		}
   	}
   	vector<vector<int> > components = {{centr}};
   	for (int i=0; i < data[centr].size(); i++){
   		int to = data[centr][i];
   		cmp.clear();
   		dfs2(to, centr);
   		components.push_back(cmp);
   	}
   	vector<int> one, two;
   	sort(components.begin(), components.end(), cmp2);
   	for (int i=0; i < components.size(); i++){
   		vector<int> t = components[i];
   		if (one.size() < two.size()){
   			for (int j=0; j < t.size(); j++) one.push_back(t[j]);
   		}
	   	else{
	   		for (int j=0; j < t.size(); j++) two.push_back(t[j]);
	   	}
   	}
   	bool was = false;
   	for (int i=0; i < one.size(); i++) if (one[i] == centr) was = true;
   	if (was){
   		vector<int> kek = two;
   		two = one;
   		one = kek;
   	}
   	if (n != 1) assert(3*one.size() >= n);
   	M = one.size();
   	vector<bool> small(n);
   	for (int i=0; i < one.size(); i++) small[one[i]] = true;
   	for (int i=0; i < two.size(); i++) small[two[i]] = false;
   	for (int i=0; i < data[centr].size(); i++){
   		int to = data[centr][i];
   		if (small[to]) dfs3(to, centr, 0, 1);
   		else dfs3(to, centr, 0, 0);
   	}
}