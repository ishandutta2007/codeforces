#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[1024];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		a[i] = a[i+1] - a[i];
	vi ans;
	for(int i=1;i<=n;i++) {
		bool ok = true;
		for(int j=i;j<n;j++)
			if(a[j] != a[j-i]) {
				ok = false;
				break;
			}
		if(ok) ans.PB(i);
	}
	cout << ans.size() << endl;
	for(int e:ans) cout << e << " ";
}