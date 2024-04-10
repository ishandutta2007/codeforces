#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	vector<int>	ans;
	int cur = 1;
	for (int i = 0; i < n; i++){
		if (a[i] == cur){
			ans.push_back(i + 2001);
			cur++;
		}
	}

	cout << ans.size() << endl;
	for (int v:ans)
		cout << v << " ";
	cout << "\n";
	return 0;
}