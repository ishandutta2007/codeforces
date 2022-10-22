//We are the fortunate ones, Imitations of Rebellion..

#include<iostream>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n;
ll vec[MAXN], p[MAXN], x = 0;
map<ll, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i], p[i + 1] = p[i] + vec[i], mp[p[i+1]]++;
	int mn = 1e9;
	for (int i = 0; i < n; i++){
		mn = min(mn, n - mp[-x]);
		mp[vec[i] - x]--;
		x -= vec[i];
		mp[-x]++;
	}
	cout << mn << "\n";
	return 0;
}