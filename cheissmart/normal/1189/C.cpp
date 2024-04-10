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

int a[1000005], s[18][1000005], t[18][1000005], lg[1000005];

int main()
{
	IO_OP;
	
	int n, q;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		s[0][i] = a[i];
	for(int i=1;i<18;i++) {
		for(int j=0;j<n;j++) {
			s[i][j] = (s[i-1][j] + s[i-1][j+(1<<(i-1))]) % 10;
			t[i][j] = t[i-1][j] + t[i-1][j+(1<<(i-1))];
			if(s[i-1][j] + s[i-1][j+(1<<(i-1))] >= 10)
				t[i][j]++;
		}
	}
	for(int i=0;i<18;i++)
		lg[1<<i] = i;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		int k = lg[r - l + 1];
		cout << t[k][l-1] << endl;
	}
}