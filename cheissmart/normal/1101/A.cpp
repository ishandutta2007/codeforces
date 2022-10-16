#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
    #define EB emplace_back
#define ALL(c) c.begin(),c.end()
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
		int l, r, d, i;
		cin >> l >> r >> d;
		if(d < l) cout << d << endl;
        else cout << (r/d+1) * d << endl;
	}
}