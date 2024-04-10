#include <iostream>
#include <vector>

using namespace std;

int a[1024], b[1024];

int main()
{
	int n, r;
	vector<int> v;
	cin >> n >> r;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(a[i]) {
			v.push_back(i);
			for(int j=max(0, i-r+1);j<=i+r-1;j++)
				b[j] = 1;
		}
	}
	for(int i=0;i<n;i++) {
		if(b[i] == 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	int j = 0, ans = 0;
	for(int i=0;i<n;) {
		while(v[j]-r+1 <= i && v[j]+r-1 >= i) {
			j++;
		}
		i = v[j-1] + r;
		ans++;
	}
	cout << ans << endl;
}