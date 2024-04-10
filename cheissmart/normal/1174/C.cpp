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

int a[100005], ct = 1;

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=2;i<=n;i++) {
		if(a[i]) continue;
		a[i] = ct++;
		for(int j=i*i;j<=n;j+=i)
			a[j] = a[i];
	}
	for(int i=2;i<=n;i++)
		cout << a[i] << " ";
	
}