#include<iostream>

using namespace std;

int main(){
	int n;	cin >> n;
	if (n < 3)	
		cout << -1 << endl;
	else{
		cout << 2 << " " << 3 << " " << 1 << " ";
		for (int i = 0; i < n - 3; i++)
			cout << 1 << " ";
		cout << endl;
	}
	return	0;
}