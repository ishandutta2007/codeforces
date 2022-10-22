#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int C = 200;

int fp[MAXN];
bitset<MAXN> p, nope[C];
int n, f, gr[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i < MAXN; i++)
		if (!fp[i])
			for (int j = i; j < MAXN; j += i)
				fp[j] = i;
	for (int i = 2; i < MAXN; i++)
		if (i == fp[i] || i/fp[i] == fp[i/fp[i]])
			p[i] = 1;

	cin >> n >> f;
	p[f] = 0;
	for (int i = 0; i < MAXN; i++){
		while (nope[gr[i]][i]) gr[i]++;
		nope[gr[i]] |= p << i;
	}

	int x = 0;
	while (n--){
		int a, b, c; cin >> a >> b >> c;
		a = b-a-1;
		c = c-b-1;
		x ^= gr[a]^gr[c];
	}

	if (x)
		cout << "Alice\nBob\n";
	else
		cout << "Bob\nAlice\n";
	return 0;
}