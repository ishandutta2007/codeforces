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
	
	int k;
	string v = "aeiou";
	cin >> k;
	for(int i=5;i<=k;i++) {
		if(k % i == 0 && k / i >= 5) {
			int n = i, m = k / n;
			for(int j=0;j<n;j++) {
				for(int l=0;l<m;l++) {
					cout << v[(j+l)%5];
				}
			}
			return 0;
		}
	}
	cout << -1 << endl;
}