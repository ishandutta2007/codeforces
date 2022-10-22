#include<iostream>
#include<algorithm>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const int SQRT = 550;
const int MAXN = 3e5 + 3;

int n;
int w[MAXN];
ll save[MAXN];
pair<pair<int, int>, int>	vec[MAXN];
ll ans[MAXN];

bool cmp(pair<pair<int, int>, int>	a, pair<pair<int, int>, int>	b){
	if (a.first.second != b.first.second)
		return	a.first.second < b.first.second;
	return	a.first.first > b.first.first;
}

void get(){
	int b = 0;
	for (int i = 1; i < SQRT; i++){
		memset(save, 0, sizeof(save));
		for (int j = n - 1; j >= 0; j--){
			if (j + i >= n)
				save[j] = w[j];
			else
				save[j] = w[j] + save[j + i];

			while (vec[b].first.second == i && vec[b].first.first == j){
				ans[vec[b].second] = save[j];
				b++;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> w[i];

	int q;	cin >> q;
	for (int i = 0; i < q; i++){
		int a, b;	cin >> a >> b;	a--;
		vec[i] = {{a, b}, i};
		if (b >= SQRT){
			ll ret = 0;
			for (; a < n; a += b)
				ret += w[a];
			ans[i] = ret;
		}
	}		
	sort(vec, vec + q, cmp);
	get();
	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}