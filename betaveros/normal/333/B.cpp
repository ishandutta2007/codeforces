#include <iostream>
using namespace std;
#define MAXSIZE 1005
bool rows[MAXSIZE];
bool cols[MAXSIZE];
int size, banned;

void reset() {
	rows[1] = rows[size] = cols[1] = cols[size] = false;
	for (int i = 2; i <= size - 1; i++){
		rows[i] = true;
		cols[i] = true;
	}
}

void readInput() {
	cin >> size >> banned;
	reset();
	for (int i = 0; i < banned; i++){
		int r, c;
		cin >> r >> c;
		rows[r] = false;
		cols[c] = false;
	}
}

int maxPoints() {
	int p = 0;
	for (int i = 2; i <= size - 1; i++){
		if (i * 2 - 1 == size) {
			if (rows[i] || cols[i]) p++;
		} else {
			if (rows[i]) p++;
			if (cols[i]) p++;
		}
	}
	return p;
}

int main() {
	readInput();
	cout << maxPoints() << endl;
}