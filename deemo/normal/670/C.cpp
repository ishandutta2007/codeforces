#include<iostream>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN], b[MAXN];
map<int, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		mp[x]++;
	}
	int m;	cin >> m;
	pair<pair<int, int>, int> ans = {{-1, -1}, -1};
	for (int i = 0; i < m; i++)	cin >> a[i];
	for (int i = 0; i < m; i++)	cin >> b[i];
	for (int i = 0; i < m; i++){
		ans = max(ans, {{mp[a[i]], mp[b[i]]}, i+1});
	}
	cout << ans.second << "\n";
	return 0;	
}