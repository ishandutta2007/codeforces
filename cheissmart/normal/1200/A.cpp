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

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	set<int> s;
	for(int i=0;i<10;i++)
		s.insert(i);
	for(int i=0;i<n;i++) {
		char c;
		cin >> c;
		if(c == 'L') {
			s.erase(s.begin());
		} else if(c == 'R') {
			s.erase(*s.rbegin());
		} else {
			s.insert(c-'0');
		}
	}
	for(int i=0;i<10;i++)
		if(s.count(i))
			cout << 0;
		else
			cout << 1;
}