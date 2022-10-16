#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int n;
	set<int> s;
	cin >> n;
	s.insert(n);
	while(true) {
		n++;
		while(n % 10 == 0) n /= 10;
		if(s.count(n)) break;
		s.insert(n);
	}
	cout << s.size() << endl;
}