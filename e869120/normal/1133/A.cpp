#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int h1, m1, h2, m2, t1, t2;

int main() {
	scanf("%02d:%02d", &h1, &m1); t1 = h1 * 60 + m1;
	scanf("%02d:%02d", &h2, &m2); t2 = h2 * 60 + m2;

	int V = (t1 + t2) / 2; if (t1 > t2) V += 720; V %= 1440;
	printf("%02d:%02d\n", V / 60, V % 60);
	return 0;
}