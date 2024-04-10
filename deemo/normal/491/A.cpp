#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a, b;	cin >> a >> b;
	if (b == 0)
		for (int i = 1; i <= a + 1; i++)
			cout << i << " ";
	else if (a == 0)
		for (int i = b + 1; i; i--)
			cout << i << " ";
	else{
		int n = a + b + 1;
		cout << 1 << " ";
		for (int i = 0; i < a - 1; i++)
			cout << i + 2 << " ";
		
		cout << a + b + 1 << " ";
		for (int i = n - 1; i >= n - b; i--)
			cout << i << " ";
	}

	cout << "\n";
	return	0;
}