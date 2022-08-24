#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

struct Edge{int to; int symb;};
vector<vector<Edge> > data;
void add(int u, int v, vector<int> &letters){
	int now = u;
	for (int j=0; j < letters.size()-1; ++j){
		data.push_back({});
		data[now].push_back({data.size()-1, letters[j]});
		now = data.size()-1;
	}
	data[now].push_back({v, letters.back()});
}

struct Path{int len; int ans; int last; int S;};
vector<Path> d;
vector<int> code;
const int mod = 1000000007;
const int INF = 1e9;

int sum(int x, int y){
	if (x+y<0) return x+y+mod;
	if (x+y >= mod) return x+y-mod;
	return x+y;
}

int mult(int x, int y){
	return ((ll) x * (ll) y) % (ll) mod;
}

bool cmp(pair<int, int> &a, pair<int, int> &b){
	if (code[a.first] != code[b.first]) return (code[a.first] < code[b.first]);
	return (a.second < b.second);
}

bool cmp2(int x, int y){
	pair<int, int> a = {d[x].last, d[x].S}, b = {d[y].last, d[y].S};
	return cmp(a, b);
}

int main()
{
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	for (int i=0;i<n;++i) data.push_back({});
	for (int i=0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		u--, v--;
		vector<int> letters;
		int cur = i+1;
		while (cur > 0){
			letters.push_back(cur%10);
			cur /= 10;
		}
		reverse(letters.begin(), letters.end());
		add(v, u, letters);
		add(u, v, letters);
	}
	int N = data.size();
	code.assign(N, -1);
	d.assign(N, {INF, 0, -1});
	d[0] = {0, 0, -1};
	vector<int> latest = {0};
	while (latest.size()){
		vector<int> nlatest;
		for (int i=0; i < latest.size(); ++i){
			int vertex = latest[i];
			for (int j=0; j < data[vertex].size(); ++j){
				int to = data[vertex][j].to, S = data[vertex][j].symb;
				if (d[to].len - 1 > d[vertex].len){
					d[to] = {d[vertex].len+1, sum(S, mult(10, d[vertex].ans)), vertex, S};
					nlatest.push_back(to);
				}
				else if (d[to].len - 1 < d[vertex].len) continue;
				else{
					pair<int, int> a = {d[to].last, d[to].S}, b = {vertex, S};
					if (cmp(b, a)){
						d[to] = {d[vertex].len+1, sum(S, mult(10, d[vertex].ans)), vertex, S};
					}
				}
			}
		}
		sort(nlatest.begin(), nlatest.end(), cmp2);
		int cur = 0;
		for (int i=0;i<nlatest.size();++i){
			if (i!=0 && code[d[nlatest[i]].last] == code[d[nlatest[i-1]].last] && d[nlatest[i]].S == d[nlatest[i-1]].S){
				code[nlatest[i]] = cur-1;
			}
			else code[nlatest[i]]=cur++;
		}
		latest = nlatest;
	}
	for (int i=1;i<n;++i){
		cout << d[i].ans << "\n";
	}
}