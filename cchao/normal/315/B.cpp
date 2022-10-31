#include <cstdio>
#include <iostream>
using namespace std;
long long n, m, arr[100010];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> arr[i];

	long long delta = 0;
	while(m--) {
		int op; long long a, b;
		scanf("%d", &op);
		if(op==1) {
			cin >> a >> b;
			arr[a] = b - delta;
		}
		else if(op==2) {
			cin >> a;
			delta += a;
		}
		else {
			cin >> a;
			cout << arr[a] + delta << endl;
		}
	}
	return 0;
}