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

int m[50], ct[6];

int main()
{
	IO_OP;

	int r[] = {4, 8, 15, 16, 23, 42};
	for(int i=0;i<6;i++)
		m[r[i]] = i;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		int pos = m[t];
		if(pos == 0) ct[pos]++;
		else {
			if(ct[pos-1]) {
				ct[pos]++;
				ct[pos-1]--;
			}
		}
	}
	cout << n - ct[5]*6 << endl;
}