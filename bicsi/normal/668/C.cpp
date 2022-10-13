#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;
double Pref[MAXN], Suff[MAXN];
double PA[MAXN], PB[MAXN];

bool bad(int i) {
	double a = PA[i] - PA[i - 1];
	double b = PB[i] - PB[i - 1];

	double rez = Pref[i - 1] + a * PB[i - 1] + b * PA[i - 1] + a * b;
	if(fabs(rez - Pref[i]) < 1e-7)
		return false;
	return true;
}

void getSols(int i) {
	double prod = Pref[i];
	double b = Suff[i + 1];

	//b = 1 - (sum) + (prod)
	double sum = 1 - b + prod;

	//Stim suma si produsul -> profit
	double disc = sqrt(fabs(sum * sum - 4 * prod));
	PA[i] = (sum + disc) / 2;
	PB[i] = (sum - disc) / 2;

	if(bad(i)) swap(PA[i], PB[i]);
}

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; ++i) {
		scanf("%lf", &Pref[i]);
		Pref[i] += Pref[i - 1];
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%lf", &Suff[i]);
	}
	for(int i = n; i >= 1; --i) {
		Suff[i] += Suff[i + 1];
	}

	for(int i = 1; i <= n; ++i) {
		getSols(i);
	}

	cout << fixed << setprecision(12);
	for(int i = 1; i <= n; ++i) {
		printf("%lf ", PA[i] - PA[i - 1]);
	}
	printf("\n");
	for(int i = 1; i <= n; ++i) {
		printf("%lf ", PB[i] - PB[i - 1]);
	}
	printf("\n");

	return 0;
}