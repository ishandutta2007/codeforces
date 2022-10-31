#include <iostream>
using namespace std;
#define BIG 100004
char ds[BIG];
int len;

void printWithout(int ix) {
	for (int i = 0; ds[i] != '\0'; i++){
		if (i != ix) cout << ds[i];
	}
	cout << endl;
}

int main() {
	cin.getline(ds, 100002);
	int toRemove = 0;
	for (int i = 0; ds[i] != '\0'; i++){
		if (ds[i] == '0') {
			toRemove = i; break;
		}
	}
	printWithout(toRemove);
}