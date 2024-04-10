#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

map<pair<string, int>, int> to;
int tot;
vector<int> hv[100005];

void add_str(string s, const string t, int id)
{
	int mask = 0;
	rep(i, t.length()) mask |= 1 << t[i] - 'a';
	while(!s.empty() && (mask >> s.back() - 'a' & 1)) s.pop_back();
	if(to.find(MP(s, mask)) == to.end()) {
		to.insert(MP(MP(s, mask), tot));
		hv[tot].push_back(id);
		tot ++;
	} else hv[to[MP(s, mask)]].push_back(id);
}

int main()
{
	int n;
	cin >> n;
	rep1(i, n) {
		string s, t;
		cin >> s >> t;
		add_str(s, t, i);
	}
	printf("%d\n", tot);
	rep(i, tot) {
		printf("%u ", hv[i].size());
		rep(j, hv[i].size())
		printf("%d%c", hv[i][j], j == hv[i].size() - 1 ? '\n' : ' ');
	}
	return 0;
}