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
	
	int n, x = 0, y = 0;
	cin >> n;
	for(int i=0;i<n;i++)  {
		cin >> a[i];
		if(a[i] & 1)
			x++;
		else
			y++;
	}
	if(x && y)
		sort(a, a+n);

	for(int i=0;i<n;i++)
		cout << a[i] << " ";
}