#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int p[102], s[102], c[102], mp[102];
vi sc[102];
int mx[102];

int main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		cin >> p[i];
	for(int i=1;i<=n;i++) {
		cin >> s[i];
		mx[s[i]] = max(mx[s[i]], p[i]);
	}
	int ct = 0;
	for(int i=1;i<=k;i++) {
		int c;
		cin >> c;
		if(mx[s[c]] != p[c]) ct++;
	}
	cout << ct << endl;
	
}