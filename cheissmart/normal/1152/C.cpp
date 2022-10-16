#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}

int32_t main()
{
	IO_OP;
	
	int a, b, x=0;
	cin >> a >> b;
	if(a > b) swap(a, b);
	int mn = lcm(a, b);
	for(int i=1;i*i<=b-a;i++) {
		int cx = (-a%i+i)%i;
		if(lcm(a+cx, b+cx) < mn) {
			mn = lcm(a+cx, b+cx);
			x = cx;
		}
		int j = (b- a) / i;
		cx = (-a%j+j)%j;
		if(lcm(a+cx, b+cx) < mn) {
			mn = lcm(a+cx, b+cx);
			x = cx;
		}
	}
	cout << x << endl;
	
}