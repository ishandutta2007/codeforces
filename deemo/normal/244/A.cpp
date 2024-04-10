#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
vector<int>	vec[50];
bool mark[100 * 100];

int main(){
	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int x;	cin >> x;
		mark[x] = 1;
		vec[i].push_back(x);
	}

	int cnt = 1, b = 0;
	for (int i = 1; i <= n * k; i++){
		if (mark[i])	continue;
		vec[b].push_back(i);
		cnt++;
		if (cnt == n)	b++, cnt = 1;
	}
	for (int i = 0; i < k; i++){
		for (int j = 0; j < n; j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	return 0;
}