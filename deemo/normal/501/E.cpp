#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, vec[MAXN], cnt[MAXN], tc[MAXN], tc2[MAXN], f, g, tf, tg, tl, l, r, ind;
bool mark[MAXN];

bool ok(int mid, int e){
	int a = min(mid, n - e - 1);
	if (tl < a)	return	false;
	
	if (mid <= f && g <= e)	
		return r < e + 1 && mid - 1 < l;
	if (n % 2 && vec[f] != ind)	return	false;

	if (mid > f)
		return mid <= tg && mark[f - (mid - g)];
	return e >= tf && mark[g + (f - e)];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i], cnt[vec[i]]++;

	g = n/2;	f = g - bool(n % 2 == 0);
	tg = g, tf = f;
	while (tf >= 0 && vec[tf] == vec[tg])	tf--, tg++;
	int ff = 0;
	for (int i = 0; i < MAXN; i++)
		if (cnt[i] % 2){
			ff++;
			ind = i;
		}
	if (ff > 1){
		cout << "0\n";
		return	0;
	}
	
	for (; l < n; l++){
		tc[vec[l]]++;
		if (tc[vec[l]] * 2 > cnt[vec[l]])	break;
	}
	memset(tc, 0, sizeof(tc));
	r = n - 1;
	for (; r >= 0; r--){
		tc[vec[r]]++;
		if (tc[vec[r]] * 2 > cnt[vec[r]])	break;
	}

	for (; tl <= f; tl++)
		if (vec[tl] != vec[n - tl - 1])	break;

	memset(tc, 0, sizeof(tc));
	int cc = 0;
	for (int i = 0; i <= f; i++){
		int a = vec[i], b = vec[n - i - 1];
		if (tc[a] != tc2[a])	cc--;
		if (tc[b] != tc2[b])	cc--;

		tc[a]++;
		tc2[b]++;
		if (tc[a] != tc2[a])	cc++;
		if (tc[b] != tc2[b])	cc++;

		if (cc == 0)	mark[i] = mark[n - i - 1] = 1;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++){
		int b = 0, e = i, ret = -1;
		while (b <= e){
			int mid = (b + e)/ 2;
			if (ok(mid, i))
				ret = mid, b = mid + 1;
			else
				e = mid - 1;
		}
		ans += ret + 1;
	}
	cout << ans << "\n";
	return	0;
}