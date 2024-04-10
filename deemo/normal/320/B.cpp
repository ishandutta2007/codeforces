#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int max_n = 120;

int l[max_n], r[max_n], sz;
bool mark[max_n];

void dfs(int v){
	mark[v] = 1;
	for (int i = 0; i < sz; i++){
		if (mark[i])	continue;
		if (l[v] > l[i] && l[v] < r[i])	dfs(i);
		else if (r[v] > l[i] && r[v] < r[i])	dfs(i);
	}
}

int main(){
	int q;	cin >> q;
	while (q--){
		int type;	cin >> type;
		if (type == 1){
			cin >> l[sz] >> r[sz];
			sz++;
		}
		else{
			int a, b;	cin >> a >> b;	a--, b--;
			memset(mark, 0, sizeof(mark));
			dfs(a);
			if (mark[b])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}