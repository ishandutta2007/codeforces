#include <iostream>
#include <vector>

using namespace std;

int c[1005];

int main()
{
	int n, a[100];
	vector<int> v;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=n-1;i>=0;i--) {
		if(c[a[i]] == 0) v.push_back(a[i]), c[a[i]] = 1;
	}
	cout << v.size() << endl;
	for(int i=v.size()-1;i>=0;i--) cout << v[i] << " ";
	cout << endl;
}