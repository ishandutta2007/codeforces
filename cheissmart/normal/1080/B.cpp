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
	
	int q;
	cin >> q;
	while(q--) {
		int l, r, pl, pr;
		cin >> l >> r;
		l--;
		if(l & 1) pl = -(l+1)/2;
		else pl = l/2;
		if(r & 1) pr = -(r+1)/2;
		else pr = r/2;
		
		cout << pr - pl << endl;
	}
}