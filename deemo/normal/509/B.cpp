#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 10;

int n, k, a[MAXN];
vector<int>	vec[200];

int main(){
	cin >> n >> k;
	int mini = 1e9, maxi = -1;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mini = min(mini, a[i]);
		maxi = max(maxi, a[i]);
	}
	if (maxi - mini > k){
		cout << "NO\n";
		return	0;
	}

	bool fl = 1;
	int c = 0;
	while (fl){
		fl = 0;
		for (int i = 0; i < n; i++)
			if (a[i])
				vec[i].push_back(c % k + 1), fl = 1, a[i]--;
		c++;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++){
		for (int v:vec[i])
			cout << v << " ";
		cout << endl;
	}
	return	0;
}