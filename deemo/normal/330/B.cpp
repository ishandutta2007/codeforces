#include<iostream>
#include<algorithm>

using namespace std;

const int max_n = 2e3;

bool mark[max_n];

int main(){
	int n, m;	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		mark[a] = mark[b] = 1;
	}
	cout << n - 1 << endl;
	for (int i = 0; i < n; i++){
		if (mark[i])	continue;
		for (int j = 0; j < n; j++)
			if (i != j)
				cout << i + 1 << " " << j + 1 << endl;
		break;
	}
	return 0;
}