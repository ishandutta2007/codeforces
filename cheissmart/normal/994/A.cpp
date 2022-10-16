#include <iostream>

using namespace std;

int main()
{
	int n, m, a[15], b[15] = {0};
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++){
		int t;
		cin >> t;
		b[t] = 1;
	}
	for(int i=0;i<n;i++) {
		if(b[a[i]])
			cout << a[i] << " ";
	}
	cout << endl;
}