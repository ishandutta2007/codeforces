#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int a, b, r;	cin >> a >> b >> r;
	if (a > b)	swap(a, b);
	if (2 * r > a){
		cout << "Second\n";
		return 0;
	}
	cout << "First\n";
	return 0;
}