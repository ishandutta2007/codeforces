#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 20;

int n;
pair<int, int>	vec[MAXN];
int prv[MAXN], nxt[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> vec[i].first;	vec[i].second = i;
		sec[i] = vec[i].first;
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}
	sort(vec, vec + n);
	if (n <= 2){
		cout << 0 << endl;
		return	0;
	}

	ll ans = 0, sum = 0, cnt = n - 2;
	for (int i = 0; i < n - 2; i++){
		int v = vec[i].second;

		if (0 <= prv[v] && nxt[v] < n)
			ans += min(sec[prv[v]] - sum, sec[nxt[v]] - sum);
		else{
			ans += cnt * (sec[v] - sum);
			sum += (sec[v] - sum);
		}		

		cnt--;

		if (prv[v] != -1)
			nxt[prv[v]] = nxt[v];
		if (nxt[v] != n)
			prv[nxt[v]] = prv[v];
	}
	cout << ans << endl;
	return	0;
}