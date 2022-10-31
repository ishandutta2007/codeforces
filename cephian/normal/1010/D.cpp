#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


const int N = 1e6+5;
// 1 = IN
// 2 = AND
// 3 = XOR
// 4 = NOT
// 5 = OR
int type[N];
int parent[N];
vector<int> children[N];
bool normal[N];
bool wwb[N][2];
vector<int> inputs;

void get_norm(int v) {
	if(type[v] != 1) {
		for(int x : children[v])
			get_norm(x);
	}
	if(type[v] == 1) {
		normal[v] = children[v][0];
	} else if(type[v] == 2) {
		normal[v] = normal[children[v][0]] & normal[children[v][1]];
	} else if(type[v] == 3) {
		normal[v] = normal[children[v][0]] ^ normal[children[v][1]];
	} else if(type[v] == 4) {
		normal[v] = !normal[children[v][0]];
	} else if(type[v] == 5) {
		normal[v] = normal[children[v][0]] | normal[children[v][1]];
	}
}

inline int get_other(int u, int v) {
	int a = children[v][0];
	int b = children[v][1];
	if(a == u) return b;
	else return a;
}

// 1 = IN
// 2 = AND
// 3 = XOR
// 4 = NOT
void get_wwb(int v) {
	if(v == 1) {
		wwb[v][0] = 0;
		wwb[v][1] = 1;
	} else {
		int p = parent[v];
		if(type[p] == 2) {
			int other = get_other(v, p);
			wwb[v][0] = wwb[p][0];
			wwb[v][1] = wwb[p][normal[other]];
		} else if(type[p] == 3) {
			int other = get_other(v, p);
			wwb[v][0] = wwb[p][normal[other]];
			wwb[v][1] = wwb[p][!normal[other]];
		} else if(type[p] == 4) {
			wwb[v][0] = wwb[p][1];
			wwb[v][1] = wwb[p][0];
		} else if(type[p] == 5) {
			int other = get_other(v, p);
			wwb[v][0] = wwb[p][normal[other]];
			wwb[v][1] = wwb[p][1];
		}
	}
	if(type[v] != 1) {
		for(int x : children[v])
			get_wwb(x);
	}
}

int main() {	
	fio;
	int n;	
	cin >> n;
	parent[1] = -1;
	for(int i = 1; i <= n; ++i) {
		string s;
		int a, b;
		cin >> s >> a;
		if(s == "IN") {
			type[i] = 1;
			children[i].push_back(a);
			inputs.push_back(i);
		} else if(s == "AND") {
			cin >> b;
			type[i] = 2;
			children[i].push_back(a);
			children[i].push_back(b);
			parent[a] = parent[b] = i;
		} else if(s == "XOR") {
			cin >> b;
			type[i] = 3;
			children[i].push_back(a);
			children[i].push_back(b);
			parent[a] = parent[b] = i;
		} else if(s == "NOT") {
			type[i] = 4;
			children[i].push_back(a);
			parent[a] = i;
		} else if(s == "OR") {
			cin >> b;
			type[i] = 5;
			children[i].push_back(a);
			children[i].push_back(b);
			parent[a] = parent[b] = i;
		}
	}
	get_norm(1);
	get_wwb(1);

	for(int x : inputs) {
		cout << wwb[x][!children[x][0]];
	}
	cout << "\n";
}