#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 10;
const int MAX = 1e6 + 20;

int n;
ll vec[MAXN];
int d[MAX];
int tl, tr;
int cnt[MAX];
int p[20][MAX + 10];

void cal(ll x){
	ld t = sqrt(x);
	ld z = sqrt(t);
	int a = ceil(z), b = t;
	if (b != x)	b++;
	if (a >= b){
		d[x] = 0;
		return;
	}

	while (tr < b)
		cnt[d[tr++]]++;
	while (tl < a)
		cnt[d[tl++]]--;
	while (cnt[d[x]])
		d[x]++;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int maxi = 0;
	for (int i = 1; i < MAX; i++){
		cal(i);
		maxi = max(maxi, d[i]);
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < MAX; j++)
			p[i][j + 1] = p[i][j] + bool(d[j] == i);

	ll ans = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		ld a = sqrt(vec[i]);
		ld b = sqrt(a);
		int f = ceil(b), g = a;
		if (g != vec[i])	g++;
		int j = 0;
		for (j = 0; j < 10; j++)
			if (p[j][f] == p[j][g])	break;
		if (vec[i] < MAX)
			j = d[vec[i]];
		ans ^= j;
	}
	if (ans == 0)
		cout << "Rublo\n";
	else
		cout << "Furlo\n";
	return 0;
}