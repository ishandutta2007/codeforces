#include<bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

const int MAXN = 3e8 + 3;
const int SQ = 18e3;

int primes[SQ], sz;
bool mark[SQ + 2];
ui ans, n, A, B, C, D;

ui f(ui x){return A*x*x*x + B*x*x + C*x + D;}

ui get(ui p){
	ui ret = 0, temp = f(p), cur = p;
	while (p <= n){
		ret += n/ cur * temp;
		if (cur > n/ p) break;
		cur *= p;
	}
	return ret;
}

int main() {
	cin >> n >> A >> B >> C >> D;

	mark[1] = true;
	for (int i = 2; i <= SQ; i++)
		if (!mark[i]) {
			for (int j = i; j <= SQ; j += i)
				mark[j] = true;
			primes[sz++] = i;
			if (i <= n)
				ans += get(i);
		}

	for (int l = SQ+1; l <= n; l += SQ){
		memset(mark, 0, sizeof(mark));
		int r = min((int)n+1, l + SQ);
		for (int i = 0; i < sz; i++){
			int tl = (l + (primes[i]-1))/ primes[i] * primes[i];
			while (tl < r){
				mark[tl - l] = true;
				tl += primes[i];
			}
		}

		for (ui i = l; i < r; i++)
			if (!mark[i - l])
				ans += get(i);
	}

	cout << ans << "\n";
	return 0;
}