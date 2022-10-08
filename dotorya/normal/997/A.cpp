#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef long long ll;

#pragma warning(disable:4996)

char in[300050];
int main() {
	int N, X, Y;
	scanf("%d %d %d", &N, &X, &Y);
	scanf("%s", in + 1);

	vector <int> Vu;
	for (int i = 1; i <= N; i++) {
		int t = in[i] - '0';
		if (Vu.empty() || Vu.back() != t) Vu.push_back(t);
	}

	ll c = 0;
	for (auto it : Vu) if(it == 0) c++;

	ll ans;
	if (c == 0) ans = 0;
	else if (X > Y) ans = c * Y;
	else ans = Y + (c - 1)*X;
	return !printf("%lld\n", ans);
}