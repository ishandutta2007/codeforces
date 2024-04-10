#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int u[500005], v[500005], ct[500005], die[500005];
vi e[500005];

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i=1;i<=m;i++) {
			cin >> u[i] >> v[i];
			e[u[i]].PB(i);
			e[v[i]].PB(i);
		}
		vi c;
		set<int> a, b;
		for(int i=1;i<=n;i++) {
			for(int edge:e[i]) {
				ct[edge]++;
				if(ct[edge] > 1)
					a.insert(edge);
			}
			b.insert(i);
		}
		bool ok = 1;
		for(int i=n+1;i<3*n;i+=2) {
			if(a.size() == 0) {
				// assert(b.size() == n);
				cout << "IndSet" << endl;
				for(int ee:b)
					cout << ee << " ";
				cout << endl;
				ok = 0;
				break;
			}
			int edge = *a.begin();
			a.erase(a.begin());
			c.PB(edge);
			b.erase(u[edge]);
			for(int eee:e[u[edge]])
				a.erase(eee);
			b.erase(v[edge]);
			for(int eee:e[v[edge]])
				a.erase(eee);

			die[u[edge]] = die[v[edge]] = 1;
			for(int j=i;j<i+2;j++) {
				b.insert(j);
				for(int edge:e[j]) {
					if(die[u[edge]^v[edge]^j]) continue;
					ct[edge]++;
					if(ct[edge] > 1)
						a.insert(edge);
				}
			}
		}
		if(ok) {
			cout << "Matching" << endl;
			for(int i=0;i<n;i++)
				cout << c[i] << " ";
			cout << endl;
		}
		for(int i=1;i<=m;i++)
			u[i] = v[i] = ct[i] = 0;
		for(int i=1;i<=n*3;i++)
			e[i].clear();
		for(int i=1;i<=n*3;i++)
			die[i] = 0;
	}
	
}