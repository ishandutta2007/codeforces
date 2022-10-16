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

int a[200005], pos[200005], p[200005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	string s;
	cin >> s;
	s = ' ' + s;
	for(int i=1;i<n;i++) {
		p[i] = p[i-1] + s[i]-'0';
	}
	for(int i=1;i<n;i++) {
		if(a[i] != i && p[pos[i]-1]-p[i-1] != pos[i]-i) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}