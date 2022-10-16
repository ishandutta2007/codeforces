#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005];

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	int d = n - k*(k+1) / 2;
	for(int i=0;i<k;i++)
		a[i] = i + 1;
	if(d < 0) {
		cout << "NO" << endl;
		return 0;
	}
	if((n==4 && k == 2 || n == 8 && k == 3)) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;i<k;i++)
		a[i] += d / k;
	for(int i=k-d%k;i<k;i++)
		a[i]++;
	if(k != 1 && d == k-1) {
		a[1]--;
		a[k-1]++;
	}
	for(int i=1;i<k;i++)
		assert(a[i] > a[i-1] && a[i] <= a[i-1]*2);
	cout << "YES" << endl;
	for(int i=0;i<k;i++)
		cout << a[i] << " ";
}