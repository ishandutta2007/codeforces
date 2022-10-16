#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 4e5 + 5;
vi G[N];
int ct;

void NO() {
	cout << "NO" << endl;
	exit(0);
}
void add(int u, int v) {
	G[u].PB(v);
	G[v].PB(u);
}

int main()
{
	IO_OP;
	
	int n, d, k;
	cin >> n >> d >> k;
	if(d >= n)
		NO();
	if(k == 1) {
		if(n < 2 && d == 0) {
			cout << "YES" << endl;
			return 0;
		}
		if(n == 2 && d == 1) {
			cout << "YES" << endl;
			cout << "1 2" << endl;
			return 0;
		}
		NO();
	}
	for(int i=1;i<=d;i++) {
		add(i, i+1);
	}
	ct = d + 2;
	for(int i=1;i<=d+1;i++) {
		int h = min(i-1, d-i+1);
		vector<pi> q({{i,0}});
		for(int j=0;j<q.size();j++) {
			int u = q[j].F, ch = q[j].S;
			if(ch == h) continue;
			while(ct <= n && G[u].size() < k) {
				add(u, ct);
				q.EB(ct, ch+1);
				ct++;
			}
		}
	}
	if(ct != n+1)
		NO();
	cout << "YES" << endl;
	for(int i=1;i<ct;i++) {
		for(int v:G[i])
			if(v < i)
				cout << v << " " << i << endl;
	}
}