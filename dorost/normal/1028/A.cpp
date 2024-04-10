#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m;
	cin >> n >> m;
	vector <pair <int, int>> vec;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (c == 'B'){
                vec.push_back({i, j});
            }
        }
    int x = 0, y = 0;
    for (int i = 0; i < vec.size(); i++)
        x += vec[i].first, y += vec[i].second;
    cout << x / vec.size() << ' ' << y / vec.size();
}