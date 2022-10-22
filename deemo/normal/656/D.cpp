#include<iostream>

using namespace std;

int main(){
	int ret = 0;
	int x;	cin >> x;
	while (x){
		if (x % 8 == 1)	ret++;
		x /= 8;
	}
	cout << ret << "\n";
	return	0;
}