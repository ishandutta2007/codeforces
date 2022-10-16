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
	
	int n, a = 0, b = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t == 1) a++;
		else b++;
	}
	if(b == 0) {
		for(int i=0;i<n;i++)
			cout << "1 ";
		return 0;
	}
	vi ans;
	if(a >= 3) {
		a -= 3;
		ans.PB(1);
		ans.PB(1);
		ans.PB(1);
	} else if(a == 2 || a == 1) {
		ans.PB(2);
		ans.PB(1);
		a--, b--;
	}
	for(int i=0;i<b;i++)
		ans.PB(2);
	for(int i=0;i<a;i++)
		ans.PB(1);
	for(int e:ans)
		cout << e << " ";
}