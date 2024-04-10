#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a, b;	cin >> a >> b;
	if (!a && b)
		cout << "Impossible\n";
	else
		cout << a + max(0, b - a) << " " << a + max(0, b - 1) << "\n";
	return	0;
}