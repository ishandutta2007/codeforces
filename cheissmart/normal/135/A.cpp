#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(n == 1) {
		if(a[0] == 1) cout << 2 << endl;
		else cout << 1 << endl;
		return 0;
	}
	sort(a, a+n);
	cout << 1 << " ";
	for(int i=0;i<n-2;i++)
		cout << a[i] << " ";
	if(a[n-1] == 1) cout << 2;
	else cout << a[n-2];
}