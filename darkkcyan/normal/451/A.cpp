#include <iostream>
#include <algorithm>
using namespace std;

string names[] = {
	"Malvika", "Akshat", 
};

int main() {
	int n, m;
	cin >> n >> m;
	cout << names[min(n, m) % 2];
	return 0;
}