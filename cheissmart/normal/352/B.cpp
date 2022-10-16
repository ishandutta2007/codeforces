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

vi m[100005];
vector<pi> ans;

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0, tmp;i<n;i++) {
		cin >> tmp;
		m[tmp].PB(i);
	}
	for(int i=0;i<100005;i++) {
		if(m[i].size() == 1) {
			ans.PB({i, 0});
			continue;
		}
		if(m[i].size()) {
			bool flag = true;
			for(int j=0;j<m[i].size()-1;j++) {
				if(m[i][j+1] - m[i][j] != m[i][1] - m[i][0]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				ans.PB({i, m[i][1] - m[i][0]});
			}
		}
	}
	cout << ans.size() << endl;
	for(pi p:ans)
		cout << p.F << " " << p.S << endl;
}