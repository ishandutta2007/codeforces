#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 7e3 + 10;
const int XX = 1e6;

int n, d[2][MAXN], cnt[2][MAXN];
pair<int, int> q[XX];
vector<int> vec[2];

int fix(int x){
	while (x < 0) x += n;
	while (x >= n) x -= n;
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int w = 0; w < 2; w++){
		int t; cin >> t;
		vec[w].resize(t);
		for (int j = 0; j < t; j++)
			cin >> vec[w][j];
	}
	
	int h = 0, t = 0;
	d[0][0] = 2; q[t++] = {0, 0};
	d[1][0] = 2; q[t++] = {1, 0};

	while (t-h){
		auto v = q[h++];
		if (d[v.F][v.S] == 2){
			for (int u:vec[!v.F]){
				int x = fix(v.S - u);
				if (d[!v.F][x] == 0){
					d[!v.F][x] = 1;
					q[t++] = {!v.F, x};
				}
			}
		}
		else{
			for (int u:vec[!v.F]){
				int x = fix(v.S - u);
				cnt[!v.F][x]++;
				if (d[!v.F][x]) continue;
				if (cnt[!v.F][x] == vec[!v.F].size()){
					d[!v.F][x] = 2;
					q[t++] = {!v.F, x};
				}
			}
		}
	}


	for (int w = 0; w < 2; w++){
		for (int i = 1; i < n; i++)
			if (d[w][i] == 1)
				cout << "Win ";
			else if (d[w][i] == 2)
				cout << "Lose ";
			else
				cout << "Loop ";
		cout << "\n";
	}
	return 0;
}