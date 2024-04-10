#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

// ----- DIGRAPH -----
void dg_euler(int v, vi& path, vvi& G) {
	while(G[v].size()) {
		int u = G[v].back();
		G[v].pop_back();
		dg_euler(u,path,G);
	}
	path.push_back(v);
}

vvi G;
int bal[5005]={};
bool mark[5005]={0};

int gc(char a) {
	if('a' <= a and a <= 'z') return a-'a';
	if('A' <= a and a <= 'Z') return 26+a-'A';
	return 2*26+a-'0';
}

char gi(int i) {
	if(i < 26) return i+'a';
	if(i < 2*26) return i-26+'A';
	return i-2*26+'0';
}

int g(char a, char b) {
	return gc(a)*62+gc(b);
}

vi L;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	G = vvi(5005);
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int a = g(s[0],s[1]), b = g(s[1],s[2]);
		G[a].pb(b);
		++bal[a];
		--bal[b];
		mark[a] = mark[b] = true;
		
	}
	int v = -1,bm1=0;
	for(int i = 0; i < 62*62; ++i) {
		if(!mark[i]) continue;
		if(bal[i] == 1) {
			if(v != -1) {
				cout << "NO\n";
				return 0;
			}
			v = i;
		} else if(bal[i] == -1) {
			if(bm1) {
				cout << "NO\n";
				return 0;
			}
			bm1 = 1;
		} else if(bal[i] != 0) {
			cout << "NO\n";
			return 0;
		}
	}
	if(v==-1) {
		if(bm1 != 0) {
			cout << "NO\n";
			return 0;
		}
		for(int i = 0; i < 62*62; ++i) {
			if(G[i].empty()) continue;
			v = i;
			break;
		}
	} else {
		if(bm1 != 1) {
			cout << "NO\n";
			return 0;
		}
	}
	// cout << v << endl;
	dg_euler(v,L,G);
	if(L.size() != n+1) {
		cout << "NO\n";
		return 0;
	} else {
		cout << "YES\n";
		cout << gi(L.back()/62);
		for(int i = L.size()-1; i >= 0; --i) {
			cout << gi(L[i]%62);
		}
		cout << "\n";
	}
	
	
	return 0;
}