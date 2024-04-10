#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;	cin >> n;
	cout << 2 * (n/3) +bool(n%3) << "\n";
	return 0;
}