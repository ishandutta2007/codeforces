#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int max_n = 1e5 + 10;

vector<int>	vec;
map<int, int>	cnt;
int n;
int a[max_n];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		vec.push_back(a[i]);
		cnt[a[i]]++;
		int x = a[i];
		while (cnt[x] == 2){
			cnt[x] = 0;
			cnt[++x]++;
			vec.push_back(x);
		}
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	int maxi = vec.back();
	int ans = 0;
	for (int u:vec)
		if (cnt[u] == 1)	ans--;
	ans += maxi + 1;
	cout << ans << endl;
	return 0;
}