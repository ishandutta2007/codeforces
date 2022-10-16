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
	string s, t;
	cin >> n >> s;
	for(int i=0;i<n;) {
		int j = i;
		while(i < n && s[j] == s[i])
			i++;
		if(i-j == 1 || t.size() % 2 == 0)
			t += s[j];
		else
			t += s[j], t += s[j];
	}
	if(t.size() % 2)
		t = t.substr(0, t.size()-1);
	cout << s.size() - t.size() << endl;
	cout << t << endl;
	
}