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

	int t;
	cin >>t;
	while(t--) {
		int n, a = 0, b = 0, c = 0;
		cin >> n;
		for(int i=0;i<n;i++) {
			int x;
			cin >> x;
			if(x % 3 == 0) a++;
			else if(x % 3 == 1) b++;
			else c++;
		}
		int d = min(b, c);
		a += d, b -= d, c -= d;
		a += b / 3, a += c / 3;
		b %= 3, c %= 3;
		a += min(c / 2, b / 2);
		cout << a << endl;
	}

}