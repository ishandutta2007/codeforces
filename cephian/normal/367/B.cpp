#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;

const int N = 2e5+5;
int a[N], b[N];

map<int,int> freq;

void change(int a, int d) {
	freq[a] += d;
	if(freq[a] == 0)
		freq.erase(a);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
		change(b[i], -1);
	}

	vector<int> ans;
	for(int i = 0; i < p; ++i) {
		queue<int> all;
		for(int j = 0; i+j*p < n; ++j) {
			all.push(a[i+j*p]);
			change(a[i+j*p], 1);
			if((int)all.size() > m) {
				change(all.front(), -1);
				all.pop();
			}
			if(j >= m-1 && freq.empty()) {
				ans.push_back(i+(j-m+1)*p+1);
			}
		}
		while(all.size()) {
			change(all.front(), -1);
			all.pop();
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for(auto x : ans)
		cout << x << " ";
	cout << "\n";
}