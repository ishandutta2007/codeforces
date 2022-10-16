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
	
	int ct1, ct2, ct3, ct4;
	cin >> ct1 >> ct2 >> ct3 >> ct4;
	if((ct3 && (ct1 == 0 || ct4 == 0)) || ct1 != ct4) cout << 0 << endl;
	else cout << 1 << endl;
	
}