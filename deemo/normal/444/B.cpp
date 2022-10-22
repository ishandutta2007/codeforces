#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAXN = 1e5 + 20;

int n, d, a[MAXN], b[MAXN], pos[MAXN], rnd = 500;
ll x;
int sec[MAXN], t;

int nxt(){return	x = (x * 37 + 10007) % MOD;}

void init(){
	iota(a, a + n, 1);
	for (int i = 0; i < n; i++)
		swap(a[i], a[nxt() % (i + 1)]);
	
	fill(b, b + d, 1);
	for (int i = 0; i < n; i++)
		swap(b[i], b[nxt() % (i + 1)]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d >> x;
	init();
	
	for (int i = 0; i < n; i++){
		pos[a[i]] = i;
		if (b[i] == 1)
			sec[t++] = i;
	}

	for (int i = 0; i < n; i++){
		int zz = 0;
		for (int j = n; j >= max(1, n - rnd); j--){
			if (pos[j] > i)	continue;
			if (b[i - pos[j]] == 1){
				zz = j;
				break;
			}
		}
		
		if (zz == 0)
			for (int j = 0; j < t && sec[j] <= i; j++)
				zz = max(zz, a[i - sec[j]]);
		cout << zz << "\n";
	}
	return	0;
}