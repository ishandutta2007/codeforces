#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 100;

int n;
int vec[MAXN];
vector<int>	c[4];

void show(){
	sort(vec, vec + n);
	if (vec[n - 1] == 0)
		cout << 0 << endl;
	else{
		reverse(vec, vec + n);
		for (int i = 0; i < n; i++)
			cout << vec[i];
		cout << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
		c[vec[i] % 3].push_back(vec[i]);
	}
	sort(vec, vec + n);
	if (vec[0] != 0){
		cout << -1 << endl;
		return 0;
	}
	if (sum % 3 == 0){
		show();
		return 0;
	}

	for (int i = 0; i < 3; i++)
		sort(c[i].begin(), c[i].end());
	
	int z = sum % 3;
	if (c[z].size()){
		int t = c[z][0];
		int pos = lower_bound(vec, vec + n, t) - vec;
		swap(vec[pos], vec[n - 1]);
		n--;
		sort(vec, vec + n);
		show();
		return 0;
	}

	if (z == 2)	z = 1;
	else	z = 2;
	if (c[z].size() > 1){
		for (int i = 0; i < 2; i++){
			int t = c[z][i];
			int pos = lower_bound(vec, vec + n, t) - vec;
			swap(vec[pos], vec[n - 1]);
			n--;
			sort(vec, vec + n);
		}
		show();
		return 0;
	}
	cout << -1 << endl;
	return 0;
}