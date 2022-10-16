#include <iostream>

using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	if(m == 0) {
		cout << n << " " << n << endl;
		return 0;	
	}
	if(n == 2) {
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	long long sm = 0, a = n, b = n - m*2;
	for(long long i=0;i<=n;i++) {
		if(sm >= m) {
			a -= i;
			break;
		}
		sm += i;
	}
	cout << max(0LL, b) << " " << a << endl;
}