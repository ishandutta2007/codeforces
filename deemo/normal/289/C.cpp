#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;	cin >> n;
	int k;	cin >> k;
	if (k > n){
		cout << -1 << endl;
		return 0;
	}
	if (k == 1){
		if (n > 1)
			cout << -1 << endl;
		else
			cout << "a" << endl;
		return 0;
	}
	for (int i = 0; i < n - k + 2; i++)
		if (i % 2 == 0)	cout << "a";
		else	cout << "b";
	for (int i = 2; i < k; i++)
		cout << char('a' + i);
	cout << endl;
	return 0;
}