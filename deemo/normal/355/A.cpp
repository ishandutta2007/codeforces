#include<iostream>

using namespace std;

int main(){
	int a, b, c = 0;	cin >> a >> b;
	if (b == 0){
		if (a == 1)
			cout << "0\n";
		else
			cout << "No solution\n";
		return	0;
	}

	if (a == 1){
		cout << b << "\n";
		return	0;
	}
		
	for (int i = 0; i < a - 1; i++)
		cout << "1", c = (c + 1) % 9;
	for (int i = 0; i < 10; i++){
		int z = (c + i) % 9;
		if (z == 0)	z = 9;
		if (z == b){
			cout << i << "\n";
			break;
		}
	}
	return	0;
}