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

int p[100005], c[100005], nc[100005], nc1[100005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> p[i] >> c[i];
		if(p[i] == -1) continue;
		nc[p[i]]++;
		nc1[p[i]] += c[i];
	}
	vi ans;
	for(int i=1;i<=n;i++) {
		if(c[i] == 1 && nc[i] == nc1[i])
			ans.PB(i);
	}
	if(ans.size() == 0)
		cout << -1 << endl;
	for(int i:ans)
		cout << i << " ";
	
}