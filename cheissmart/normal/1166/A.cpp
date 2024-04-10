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

int ct[30];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		ct[s[0]-'a']++;
	}
	int ans = 0;
	for(int i=0;i<26;i++) {
		int x = ct[i] / 2;
		int y = ct[i] - x;
		ans += x*(x-1)/2 + y*(y-1) / 2;
	}
	cout << ans << endl;
}