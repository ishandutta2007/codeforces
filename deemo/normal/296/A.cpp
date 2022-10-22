#include<iostream>

using namespace std;

const int MAX = 2e3;

int cnt[MAX];

int main(){
	int n;	cin >> n;
	int maxi = 0;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		cnt[temp]++;
		maxi = max(maxi, cnt[temp]);
	}
	int g = n/2;
	if (n % 2 == 1)	g++;
	if (maxi <= g)	cout << "YES" << endl;
	else	cout << "NO\n";
	return 0;
}