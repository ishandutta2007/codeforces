#include<iostream>
#include<algorithm>

using namespace std;

int n, ans;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			int x;	cin >> x;
			if (i == n/2 || j == n/2 || i == j || n - i-1 == j)
				ans += x;
		}
	cout << ans << endl;
	return 0;
}