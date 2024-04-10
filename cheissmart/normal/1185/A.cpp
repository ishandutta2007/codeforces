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
	
	int a[3], d, ans = 0;
	for(int i=0;i<3;i++)
		cin >> a[i];
	cin >> d;
	sort(a, a+3);
	ans += max(0, d - (a[1] - a[0]));
	ans += max(0, d - (a[2] - a[1]));
	cout << ans << endl;	
}