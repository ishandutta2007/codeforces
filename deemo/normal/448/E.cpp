#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int C = 1e5;
const int MAX = 5e5 + 10;

ll x, k, sz;
vector<ll>	vec;
ll ans[MAX];

void get(int ind, int rem){
	if (rem == 0){
		ans[sz++] = vec[ind];
		return;
	}
	if (ind == 0){
		ans[sz++] = 1;
		return;
	}

	for (int i = 0; sz < C && i <= ind; i++)
		if (vec[ind] % vec[i] == 0){
			get(i, rem - 1);
			if (sz >= C)	return;
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> k;
	if (x == 1){
		cout << 1 << endl;
		return	0;
	}

	if (k >= C)
		fill(ans, ans + C, 1), sz = C;
	else if (k == 0)
		ans[sz++] = x;
	else{
		for (ll i = 1; i * i <= x; i++)
			if (x % i == 0){
				vec.push_back(i);
				if (i * i == x)	continue;
				vec.push_back(x/i);
			}
		sort(vec.begin(), vec.end());

		for (int i = 0; sz < C && i < (int)vec.size(); i++)
			get(i, k - 1);
	}

	for (int i = 0; i < sz; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return	0;	
}