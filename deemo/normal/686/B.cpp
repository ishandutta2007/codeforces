#include<iostream>
#include<algorithm>

using namespace std;

int n, a[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	bool fl = 1;
	while (fl){
		fl = 0;
		for (int i = 0; i + 1 < n; i++)
			if (a[i] > a[i + 1]){
				cout << i + 1 << " " << i + 2 << "\n";
				swap(a[i], a[i + 1]);
				fl = 1;
				break;
			}
	}
	return 0;
}