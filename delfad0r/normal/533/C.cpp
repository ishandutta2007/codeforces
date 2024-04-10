#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int X1, Y1, X2, Y2;
	scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	if(max(X2, Y2) >= X1 + Y1 || (X2 >= X1 && Y2 >= Y1))
		printf("Polycarp\n");
	else
		printf("Vasiliy\n");
}