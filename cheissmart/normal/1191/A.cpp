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
	
	int x;
	cin >> x;
	if(x % 4 == 1) {
		cout << 0 << " A" << endl;
	} else if(x % 4 == 2) {
		cout << 1 << " B" << endl;
	}  else if(x % 4 == 3) {
		cout << 2 << " A" << endl;
	}  else{
		cout << 1 << " A" << endl;
	} 
	
}