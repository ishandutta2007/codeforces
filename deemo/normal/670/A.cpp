//Nothing Scares me anymore..

#include<iostream>

using namespace std;

int main(){
	int n;	cin >> n;
	cout << n/7 * 2 + (n%7 > 5) << " ";
	cout << n/7 * 2 + min(2, n%7) << "\n";
	return 0;
}