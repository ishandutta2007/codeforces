#include<iostream>
#include<algorithm>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 10;

int n, k, vec[MAXN], d[MAXN], ss[MAXN];
int sec[MAXN];
map<int, int>	mp;

int get(int x){
	if (mp.count(x))	return	mp[x];
	int tx = x;
	int ret = 0;
	for (int i = 0; i < k && x >= sec[i]; i++)
		while (x % sec[i] == 0){
			ret--;
			x /= sec[i];
		}

	for (int i = 2; x/i >= i; i++)
		while (x % i == 0){
			ret++;
			x /= i;
		}
	if (x > 1)	ret++;
	return	mp[tx] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	for (int i = 0; i < k; i++)	cin >> sec[i];
	sort(sec, sec + k);
	int ans = 0;
	for (int i = 0; i < n; i++)	ans += get(vec[i]);
	int g = vec[0];
	for (int i = 0; i < n; i++){
		g = __gcd(g, vec[i]);
		ss[i] = get(g);
	}

	int t = 0;
	for (int i = n - 1; i >= 0; i--){
		ss[i] += t;
		if (ss[i] < 0){
			ans += -ss[i] * (i + 1);
			t += -ss[i];
		}
	}

	cout << ans << "\n";
	return	0;
}