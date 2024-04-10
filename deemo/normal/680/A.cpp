#include<iostream>
#include<algorithm>

using namespace std;

int a[10];

int main(){
	int sm = 0;
	for (int i = 0; i < 5; i++)
		cin >> a[i], sm += a[i];
	sort(a, a + 5);
	int ans = sm;
	for (int i = 0; i + 1 < 5; i++){
		if (a[i] == a[i + 1])
			ans = min(ans, sm - 2 * a[i]);
	}

	for (int i = 0; i + 2 < 5; i++)
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
			ans = min(ans, sm - 3 * a[i]);
	cout << ans << endl;
	return 0;
}