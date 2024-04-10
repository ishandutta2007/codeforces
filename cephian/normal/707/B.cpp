#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
const int N = 100005, INF = 0x7fffffff;
int s[N],t[N],w[N];

bool mark[N]={0};

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;

	for(int i = 0; i < m; ++i) {
		cin >> s[i] >> t[i] >> w[i];
		--s[i];
		--t[i];
	}
	
	for(int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		mark[--a] = 1;
	}
	int dst = INF;
	for(int i = 0; i < m; ++i) {
		if(mark[s[i]] == mark[t[i]]) continue;
		dst = min(dst,w[i]);
	}
	if(dst == INF) cout << "-1\n";
	else cout << dst << "\n";
	return 0;
}