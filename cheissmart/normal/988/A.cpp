#include <iostream>

using namespace std;

int m[105];

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		m[t] = i+1;
	}
	int ct = 0;
	for(int i=1;i<=100;i++)
		ct += (bool)m[i];
	if(ct < k) {
		cout << "NO" << endl;
	} else {
		int ct = 0;
		cout << "YES" << endl;
		for(int i=1;i<=100 && ct < k;i++) {
			if(m[i]) {
				cout << m[i] << " ";
				ct++;
			}
		}
		cout << endl;
	}
}