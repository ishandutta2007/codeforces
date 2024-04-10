#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n;
vvi G;

const int N = 1e5+5;
int a[N],b[N];
int col[2*N]={};

void fc(int v,int c) {
	if(col[v]) return;
	col[v] = c;
	for(int u : G[v]) {
		fc(u,3-c);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;	
	G = vvi(2*n,vi());
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		--a[i]; --b[i];
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	for(int i = 0; i < 2*n; i+=2) {
		G[i].push_back(i+1);
		G[i+1].push_back(i);
	}
	for(int i = 0; i < 2*n; ++i) {
		fc(i,1);
	}
	for(int i = 0; i < n; ++i) {
		cout << col[a[i]] << " " << col[b[i]] << "\n";
	}
	return 0;
}