#include<iostream>
#include<string>

using namespace std;

int main(){
	int n, p, q;
	cin >> n >> p >> q;
	string s;
	cin >> s;

	for (int i = 0; i * p <= n; i++){
		int t = n - i * p;
		if (t % q)	continue;

		cout << i + t / q << endl;
		for (int j = 0; j < i; j++){
			for (int w = 0; w < p; w++)
				cout << s[j * p + w];
			cout << endl;
		}
		int z = i * p;
		t /= q;
		for (int j = 0; j < t; j++){
			for (int w = 0; w < q; w++)
				cout << s[z + j * q + w];
			cout << endl;
		}
		return	0;
	}
	cout << -1 << endl;
	return 0;
}