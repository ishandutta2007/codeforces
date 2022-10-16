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

const int INF = 1e9 + 7;

vi G[1024];
int ct[1024], a[1024], b[1024];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		cin >> a[i] >> b[i];
		if(a[i] > b[i]) swap(a[i], b[i]);
		if(b[i] != n) {
			cout << "NO" << endl;
			return 0;
		}
	}
	sort(a,a+n-1);
	for(int i=0;i<n-1;i++)
		ct[a[i]]++;
	for(int i=1;i<n;i++) {
		if(ct[i] == 0) continue;
		G[i].PB(i);
		ct[i]--;
		if(ct[i] > 0) {
			for(int j=i-1;j>=1&&ct[i];j--)
				while(ct[i] && ct[j]==0) {
					ct[i]--, ct[j] = 1;
					G[i].PB(j);
				}
			if(ct[i]) {
				cout << "NO" << endl;
				return 0;
			}
		}
		ct[i] = 1;
	}
	for(int i=1;i<n;i++)
		sort(ALL(G[i]));
	cout << "YES" << endl;
	for(int i=0;i<n;i++) {
		if(G[i].size()) {
			cout << n << " " << G[i][0] << endl;
			for(int j=1;j<G[i].size();j++)
				cout << G[i][j-1] << " " << G[i][j] << endl;
		}
	}
}