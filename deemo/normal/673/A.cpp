#include<iostream>

using namespace std;

const int MAX = 100;

int n, a[MAX];

int main(){
	cin >> n;
	while (n--){
		int x;	cin >> x;
		a[--x]++;
	}
	int cnt = 0;
	for (int i = 0; i < 90; i++){
		if (a[i])	cnt = 0;
		else	cnt++;
		if (cnt == 15){
			cout << i+1 << "\n";
			return 0;
		}
	}
	cout << 90 << "\n";
	return 0;
}