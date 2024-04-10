#include <bits/stdc++.h>
#define F first
#define S second
#define ALL(v) (v).begin(), (v).end()
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef long long ll;

const int INF = 1e9 + 7;

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int b, g, n;
	cin >> b >> g >> n;
	int mxb = min(b, n);
	int mnb = n - min(g, n);
	cout << mxb - mnb + 1 << endl;
	
}