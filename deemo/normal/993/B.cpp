#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int n, m;
vector<pii> vec[2];
bool mark[20];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		vec[0].push_back({a, b});
	}
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		vec[1].push_back({a, b});
	}

	int cnt = 0, last = -1;
	for (int i = 1; i < 10; i++){
		int found = 0;
		for (int w = 0; w < 2; w++)
			for (auto x:vec[w])
				if (x.F == i || x.S == i){
					found |= 1<<w;
					break;
				}
		if (found != 3) continue;
	
		for (auto x:vec[0])
			for (auto y:vec[1])
				if (x != y && (x.F == i || x.S == i) && (y.F == i || y.S == i))
					found = 5;
		if (found == 5)
			mark[i] = true, cnt++, last = i;
	}
	if (cnt == 1)
		cout << last << "\n";
	else{
		bool fail = false;
		for (int w = 0; w < 2; w++)
			for (auto x:vec[w]) {
				int c = 0;
				for (auto y:vec[w^1])
					if (x != y){
						if (y.F == x.F || y.S == x.F) c |= 1;
						if (y.F == x.S || y.S == x.S) c |= 2;
					}
				if (c == 3) fail = true;
			}
		if (!fail)
			cout << "0\n";
		else
			cout << "-1\n";
	}
	return 0;
}