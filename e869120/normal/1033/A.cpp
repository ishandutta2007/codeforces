#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, AX, AY, BX, BY, CX, CY;

long long dim(long long px, long long py) {
	if (px >= 0 && py >= 0) return 0;
	if (px < 0 && py >= 0) return 1;
	if (px < 0 && py < 0) return 2;
	if (px >= 0 && py < 0) return 3;
	return -1;
}

int main() {
	cin >> N >> AX >> AY >> BX >> BY >> CX >> CY;
	BX -= AX; BY -= AY;
	CX -= AX; CY -= AY;

	long long V1 = dim(BX, BY), V2 = dim(CX, CY);
	if (V1 == V2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}