#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[2048];
vi m[2048];
vector<string> sol[2048];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int t;
		cin >> t;
		m[t].PB(i);	
	}
	int ct = 1, fi;
	bool ok = false;
	for(int i=0;i<2048;i++) {
		if(m[i].size() == 0) continue;
		ct *= m[i].size();
		if(ct >= 3) {
			ok = true;
			break;
		}
	}
	if(!ok) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vi sol;
	for(int i=0;i<2048 && sol.size() < 2;i++) {
		if(m[i].size() && m[i].size() > 1)
			sol.PB(i);
	}
	if(sol.size() == 1) {
		int p[][3] = {
			{0, 1, 2},
			{0, 2, 1},
			{1, 0, 2}
		};
		for(int j=0;j<3;j++) {
			for(int i=0;i<2048;i++) {
				if(m[i].size() == 0) continue;
				if(i == sol[0]) {
					for(int k=0;k<3;k++)
						cout << m[i][p[j][k]] << " ";
					for(int k=3;k<m[i].size();k++)
						cout << m[i][k] << " ";
				}
				else {
					for(int e:m[i]) cout << e << " ";
				}
			}
			cout << endl;
		}
	} else {
		for(int j=0;j<3;j++) {
			for(int i=0;i<2048;i++) {
				if(m[i].size() == 0) continue;
				if(i == sol[0]) {
					cout << m[i][j%2] << " ";
					for(int k=0;k<m[i].size();k++)
						if(k != j%2)
							cout << m[i][k] << " ";
				}
				else if(i == sol[1]) {
					cout << m[i][min(1, j)] << " ";
					for(int k=0;k<m[i].size();k++)
						if(k != min(1, j))
							cout << m[i][k] << " ";
				}
				else {
					for(int e:m[i]) cout << e << " ";
				}
			}
			cout << endl;
		}
	}
	
}