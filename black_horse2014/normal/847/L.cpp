#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1007;
int HS[N];
char str[N * N];
char t[N * 10];
int chk[N];
int cnt[N];
int p[N];
vector<string> vec;
vector<set<int> > B[N];

int main() {
	int n; scanf("%d\n", &n);
	int sz = 0;
	for (int i = 1; i <= n; i ++) {
		char TOK[] = "-";
		char TOK1[] = ",";
		gets(str);
		vec.clear();
		for (char *tok = strtok(str, TOK); tok != NULL; tok = strtok(NULL, TOK)) {
			vec.push_back(tok);
		}
		for (int j = 0; j < vec.size(); j ++) {
			for (int k = 0; k < vec[j].size(); k ++) t[k] = vec[j][k];
			t[vec[j].size()] = 0;
			int flg = 0;
			set<int> S;
			for (char *tok1 = strtok(t, TOK1); tok1 != NULL; tok1 = strtok(NULL, TOK1)) {
				int now = 0;
				if (!flg) {
					while (tok1[now] != ':') ++now;
					++now;
				}
				flg = 1;
				int val; sscanf(tok1+now, "%d", &val);
				S.insert(val);
			}
			B[i].push_back(S);
		}
		sz += B[i].size();
	}
	if (sz != 2 * (n - 1)) return puts("-1"), 0;
	vector<PII> vec;
	for (int i = 1; i < n; i ++) {
		int now = 0;
		for (int j = 1; j <= n; j ++) {
			if (chk[j]) continue;
			if (!B[j].size()) return puts("-1"), 0;
			if (B[j].size() == 1) now = j;
		}
		if (!now) return puts("-1"), 0;
		set<int> tem;
		for (int j = 1; j <= n; j ++) {
			if (chk[j]) continue;
			if (j != now) tem.insert(j);
		}
		if (tem != B[now][0]) return puts("-1"), 0;
		int par = 0, cnt = 0, pos;
		chk[now] = 1;
		for (int j = 1; j <= n; j ++) {
			if (chk[j]) continue;
			for (int k = 0; k < B[j].size(); k ++) {
				if (B[j][k].count(now)) {
					B[j][k].erase(now);
				}
				if (B[j][k].size() == 0) {
					par = j;
					pos = k;
					cnt++;
				}
			}
		}
		if (cnt != 1) return puts("-1"), 0;
		vec.push_back(PII(now, par));
		swap(B[par][pos], B[par].back());
		B[par].pop_back();
	}
	cout << n - 1 << endl;
	for (int i = 0; i < vec.size(); i ++) {
		printf("%d %d\n", vec[i].first, vec[i].second);
	}
	return 0;
}