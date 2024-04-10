#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n];
	vector <vector <int>> cnt(4);
	for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]].push_back(i + 1);
	}
	int N = min({cnt[1].size(), cnt[2].size(), cnt[3].size()});
	cout << N << endl;
	for (int i = 0; i < N; i++){
        for (int j = 1; j < 4; j++){
            cout << cnt[j][i] << ' ';
        }
        cout << endl;
	}
}