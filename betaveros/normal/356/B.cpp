#include <iostream>
#include <cstring>
using namespace std;
#define BIG 1000004

char a[BIG], b[BIG];
long long an, bn;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

long long getAnswer() {
	int al = strlen(a);
	int bl = strlen(b);
	int g = gcd(al, bl);

	long long ans = ((long long) al) * bl / g;

	for (int i = 0; i < g; i++) {
		int ahist[255]; memset(ahist, 0, sizeof(ahist));
		for (int j = i; j < al; j += g) {
			ahist[a[j]]++;
		}
		int bhist[255]; memset(bhist, 0, sizeof(bhist));
		for (int j = i; j < bl; j += g) {
			bhist[b[j]]++;
		}
		for (char c = 'a'; c <= 'z'; c++) {
			ans -= ((long long) ahist[c]) * bhist[c];
		}
	}
	return ans * (an / (bl / g));
}

int main() {
	cin >> an >> bn;
	cin.ignore();
	cin.getline(a, BIG);
	cin.getline(b, BIG);
	cout << getAnswer() << endl;


}