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

ll a[200005];

int main()
{
	IO_OP;
	
	ll n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	ll x = a[n-1], y = a[n-2];
	cout << m/(k+1)*(x*k+y) + m%(k+1)*x << endl;
}