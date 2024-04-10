#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int len[100005], sz[100005];

int32_t main()
{
	IO_OP;
	for(int i=1;i<100005;i++) {
		sz[i] = to_string(i).size();
		len[i] = len[i-1] + sz[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int k, i;
		cin >> k;
		for(i=1;k-len[i] >= 1;i++)
			k -= len[i];
		for(int j=1;;j++) {
			if(k <= sz[j]) {
				cout << to_string(j)[k-1] << endl;
				break;
			} else {
				k -= sz[j];
			}
		}
	}

}