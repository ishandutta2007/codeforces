#include<iostream>

using namespace std;

int main(){
	int n, k;	cin >> n >> k;
	int cn = 0;
	while (n--){
		int x;	cin >> x;
		if (x + k <= 5)	cn++;
	}
	cout << cn/3 << "\n";
	return	0;
}