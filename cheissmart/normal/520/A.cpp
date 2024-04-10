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
int m[26];

int main()
{
	IO_OP;
	int n;
	string s;
	cin >> n >> s;
	for(char c:s)
		m[tolower(c)-'a'] = 1;
	int ct = 0;
	for(int i=0;i<26;i++)
		ct += m[i];
	if(ct == 26)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}