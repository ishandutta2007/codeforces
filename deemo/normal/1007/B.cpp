#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

ll cnt[MAXN];
bool good[8][8][8];
int p[3], z[3], gg[8];

bool check(int a, int b, int c){
	iota(p, p + 3, 0);
	z[0] = a, z[1] = b, z[2] = c;
	do{
		bool fail = false;
		for (int i = 0; i < 3; i++)
			if (!(z[i] >> p[i] & 1)) fail = true;
		if (!fail) return true;
	}while (next_permutation(p, p + 3));
	return false;
}

ll get(int mask){
	if (mask == 7)
		return cnt[gg[mask]];
	if (__builtin_popcount(mask) == 2)
		return cnt[gg[mask]] - cnt[gg[7]];
	
	ll ret = cnt[gg[mask]];
	for (int i = 0; i < 3; i++)
		if (!(mask>>i&1))
			ret -= cnt[gg[mask|1<<i]];
	ret += cnt[gg[7]];
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j += i)
			cnt[j]++;

	for (int a = 0; a < 8; a++)
		for (int b = a; b < 8; b++)
			for (int c = b; c < 8; c++)
				good[a][b][c] = check(a, b, c);

	int te; cin >> te;
	while (te--){
		int a, b, c; cin >> a >> b >> c;
		z[0] = a, z[1] = b, z[2] = c;
		for (int mask = 0; mask < 8; mask++){
			gg[mask] = 0;
			for (int i = 0; i < 3; i++)
				if (mask>>i&1)
					gg[mask] = __gcd(gg[mask], z[i]);
		}

		ll ans = 0;
		for (a = 0; a < 8; a++)
			for (b = a; b < 8; b++)
				for (c = b; c < 8; c++)
					if (good[a][b][c]){
						ll temp = 0;
						if (a == b && b == c){
							temp = cnt[gg[a]]*(cnt[gg[a]]+1)*(cnt[gg[a]]+2)/ 6;
}
						else if (a == b)
							temp = get(a)*(get(a)+1)/ 2 * get(c);
						else if (b == c)
							temp = get(a)*get(b)*(get(b)+1)/ 2;
						else
							temp = get(a)*get(b)*get(c);
						ans += temp;
					}
		cout << ans << "\n";
	}
	return 0;
}