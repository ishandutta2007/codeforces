#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;
const int C = 26 + 1;

int n, ln, val[MAXN];
string s[MAXN];
int sz = 0, tr[C][MAXN], tval[MAXN];
bool mark[MAXN];
vector<int>	vec[MAXN], sec[MAXN];

void insert(string t, int vv){
	int cur = 0;
	int de = 0;
	for (char c:t){
		if (!tr[c - 'a'][cur])
			tr[c - 'a'][cur] = ++sz;
		cur = tr[c - 'a'][cur];
	}
	string tt = t;
	reverse(tt.begin(), tt.end());
	vec[cur].push_back(vv);
	if (t == tt)
		mark[cur] = 1;
	else{

		cur = de = 0;
		for (char c:tt){
			if (!tr[c - 'a'][cur])
				tr[c - 'a'][cur] = ++sz;
			cur = tr[c - 'a'][cur];
		}
		sec[cur].push_back(vv);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> ln;
	for (int i = 0; i < n; i++){
		cin >> s[i] >> val[i];
		insert(s[i], val[i]);
	}
	for (int i = 1; i <= sz; i++)
		sort(vec[i].begin(), vec[i].end(), greater<int>())
			, sort(sec[i].begin(), sec[i].end(), greater<int>());

	int ans = 0;
	int mx = 0;
	for (int i = 1; i <= sz; i++)
		if (!mark[i]){
			for (int j = 0; j < sec[i].size() && j < vec[i].size(); j++)
				if (sec[i][j] + vec[i][j] > 0)
					ans += sec[i][j] + vec[i][j];
		}
		else{
			for (int j = 0; j + 1< vec[i].size(); j+=2){
				if (vec[i][j] + vec[i][j + 1] > 0){
					ans += 2*(vec[i][j] + vec[i][j + 1]);
					mx = max(mx, -vec[i][j + 1]);
				}
				else
					mx = max(mx, vec[i][j]);
			}
			if (vec[i].size() & 1)
				mx = max(mx, vec[i].back());
		}
	ans >>= 1;
	ans += mx;
	cout << ans << "\n";
	return 0;
}