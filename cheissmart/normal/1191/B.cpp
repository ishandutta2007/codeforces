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
	
	vector<string> v(3);
	for(int i=0;i<3;i++)
		cin >> v[i];
	if(v[0] == v[1] && v[1] == v[2]) {
		cout << 0 << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][0]+1 == v[1][0] && v[1][0]+1 == v[2][0]) {
		cout << 0 << endl;
		return 0;
	}
	if(v[0] == v[1] || v[1] == v[2]) {
		cout << 1 << endl;
		return 0;
	}
	if(v[0][1] == v[1][1] && v[0][0]+1 == v[1][0]) {
		cout << 1 << endl;
		return 0;
	}
	if(v[0][1] == v[1][1] && v[0][0]+2 == v[1][0]) {
		cout << 1 << endl;
		return 0;
	}
	if(v[1][1] == v[2][1] && v[1][0]+1 == v[2][0]) {
		cout << 1 << endl;
		return 0;
	}
	if(v[1][1] == v[2][1] && v[1][0]+2 == v[2][0]) {
		cout << 1 << endl;
		return 0;
	}
	if(v[0][1] == v[2][1] && v[0][0]+1 == v[2][0]) {
		cout << 1 << endl;
		return 0;
	}
	if(v[0][1] == v[2][1] && v[0][0]+2 == v[2][0]) {
		cout << 1 << endl;
		return 0;
	}
	cout << 2 << endl;
}