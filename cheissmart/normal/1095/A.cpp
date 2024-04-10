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

int main()
{
	IO_OP;
	
	int n;
	string s;
	cin >> n >> s;
	for(int i=0, j=0;i<n;j++, i+=j)
		cout << s[i];
}