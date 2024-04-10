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
	
	int n, b, a, i, bb, aa;;
	cin >> n >> b >> a;
	bb = b, aa = a;
	for(i=0;i<n;i++) {
		int s;
		cin >> s;
		if(s == 0) {
			if(aa) aa--;
			else if(bb) bb--;
			else break;
		} else {
			if(bb && aa < a) bb--, aa++;
			else if (aa) aa--;
			else break;
		}
	}
	cout << i << endl;
}