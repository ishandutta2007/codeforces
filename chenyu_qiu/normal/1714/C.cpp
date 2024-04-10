#include<iostream>
using namespace std;
int main() {
	int t,i,num,j,k,count;
	cin >> t;
	for (i = 1; i <= t; i++) {
		cin >> num;
		int a[9] = { 0 };
		count = 0;
		for (j = 9; j >= 1; j--) {
			if (num == 0) break;
			else if (num >= j) {
				num = num - j;
				for (k = 1; k<=9; k++) {
					if (a[k - 1] != 0) continue;
					else {
						a[k - 1] = j;
						count++;
						break;
					}
				}
			}
		}
		for (j = count; j >= 1; j--) {
			if (j == 1) cout << a[j - 1] << "\n";
			else cout << a[j - 1];
		}
	}
}