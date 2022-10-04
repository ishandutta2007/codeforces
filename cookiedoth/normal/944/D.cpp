#include <bits/stdc++.h>
#define ll long long
#define null null

using namespace std;

const int mx = 5e3 + 228;
const int K = 26;
int n, a[mx];
string s;

int ok(vector<int> pos) {
	//cout << "ok" << endl;
	vector<int> used(K);
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		used.assign(K, 0);
		//cout << "shift = " << i << endl;
		int cur_cnt = 0;
		for (auto p : pos) {
			int p1 = (p + i) % n;
			//cout << "pos = " << p << endl;
			//cout << "letter = " << a[p1] << endl;
			if (used[a[p1]] == 0) {
				//cout << "cnt++" << endl;
				used[a[p1]] = 1;
				cur_cnt++;
			}
			else {
				if (used[a[p1]] == 1) {
					//cout << "cnt--" << endl;
					used[a[p1]] = 2;
					cur_cnt--;
				}
			}
		}
		//cout << "cur_cnt = " << cur_cnt << endl;
		cnt = max(cnt, cur_cnt);
	}
	return cnt;
}

int main() {
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - 'a';
	}
	int sum = 0;
	for (int i = 0; i < K; ++i) {
		vector<int> pos;
		for (int j = 0; j < n; ++j) {
			if (a[j] == i) {
				pos.push_back(j);
			}
		}
		sum += ok(pos);
	}
	cout << setprecision(20) << (double)sum / (double)n << endl;
}