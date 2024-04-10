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

int main()
{
	IO_OP;
	
	char c;
	string s, kb = "qwertyuiopasdfghjkl;zxcvbnm,./";
	cin >> c >> s;
	int d = 1;
	if(c == 'R') d = -1;
	for(char c:s) {
		cout << kb[find(kb.begin(), kb.end(), c)-kb.begin()+d];
	}
}