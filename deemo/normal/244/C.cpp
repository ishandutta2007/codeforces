#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 20;
const int LOG = 20 + 3;
const int MAX = 2e6 + 100;

int n, vec[MAXN];
int cnt;
bool seen[MAX];
int last[LOG], sec[LOG];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	
	for (int i = 0; i < n; i++){
		int x = vec[i];
		if (!seen[x])	seen[x] = 1, cnt++;

		int t = 0;
		for (int j = 0; j < LOG; j++)
			if (((x >> j) & 1) == 0)	
				if (last[j] != 0)
					sec[t++] = last[j] - 1;

		sort(sec, sec + t);
		reverse(sec, sec + t);
		for (int j = 0; j < t; j++){
			x |= vec[sec[j]];
			if (!seen[x])	seen[x] = 1, cnt++;
		}

		for (int j = 0; j < LOG; j++)
			if ((vec[i] >> j) & 1)
				last[j] = i + 1;
	}
	cout << cnt << endl;
	return 0;
}