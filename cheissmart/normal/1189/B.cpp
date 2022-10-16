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

int a[100005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	if(a[n-1] >= a[n-2] + a[n-3]) {
		cout << "NO" << endl;
		return 0;
	}
	swap(a[0], a[n-2]);
	sort(a+1, a+n-1);
	cout << "YES" << endl;
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
}