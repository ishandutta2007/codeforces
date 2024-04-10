#include <iostream>
using namespace std;

int main(){
	int x, y;
	cin >> x >> y;
	if (x == y)
		cout << "=" << endl;
	else if (x == 1)
		cout << "<" << endl;
	else if (y == 1)
		cout << ">" << endl;
	else if (x == 2 && y == 3)
		cout << "<" << endl;
	else if (x == 3 && y == 2)
		cout << ">" << endl;
	else if (x == 2 && y == 4 || x == 4 && y == 2)
		cout << "=" << endl;
	else if (x < y)
		cout << ">" << endl;
	else
		cout << "<" << endl;
}