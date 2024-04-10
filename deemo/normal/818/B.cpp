#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 10;

int n, m, x[MAXN], a[MAXN];
bool used[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)	cin >> x[i], x[i]--;
	memset(a, -1, sizeof(a));
	for (int i = 0; i + 1 < m; i++){
		int dif = x[i+1] - x[i];
		if (dif <= 0) dif += n;
		if (a[x[i]] == -1){
			if (used[dif]){
				cout << "-1\n";
				return 0;
			}
			used[dif] = 1;
			a[x[i]] = dif;
		}
		else{
			if (dif != a[x[i]]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	int cur = 1;
	for (int i = 0; i < n; i++){
		if (a[i] == -1){
			while (used[cur]) cur++;
			a[i] = cur++;
		}
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}