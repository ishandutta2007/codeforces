#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	int ans = 0;
	cout << "? ";
	for(int i=1;i<=100;i++)	
		cout << i << " ";
	cout << endl;
	int q;
	cin >> q;
	ans += (q >> 7) << 7;
	cout << "? ";
	for(int i=1;i<=100;i++)	
		cout << (i << 7) << " ";
	cout << endl;
	cin >> q;
	for(int i=0;i<7;i++) {
		if(q>>i&1)
			ans += (1 << i);
	}
	cout << "! " <<  ans << endl;
}