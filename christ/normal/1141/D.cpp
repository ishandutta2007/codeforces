#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char a[MN], b[MN];
vector<int> wot[26], qa, qb;
int main() {
    int n;
	scanf ("%d",&n);
	scanf ("%s",a+1); scanf ("%s",b+1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == '?') qa.push_back(i);
		else wot[a[i]-'a'].push_back(i);
	}
	vector<pii> ans;
	for (int i = 1; i <= n; i++) {
		if (b[i] == '?') qb.push_back(i);
		else {
			if (!wot[b[i]-'a'].empty()) {
				ans.emplace_back(wot[b[i]-'a'].back(),i);
				wot[b[i]-'a'].pop_back();
			} else if (!qa.empty()) {
				ans.emplace_back(qa.back(),i);
				qa.pop_back();
			}
		}
	}
	for (int ind : qb) {
		for (int i = 0; i < 26; i++) {
			if (!wot[i].empty()) {ans.emplace_back(wot[i].back(),ind), wot[i].pop_back(); goto succ;}
		}
		if (!qa.empty()) ans.emplace_back(qa.back(),ind), qa.pop_back();
		succ:;
	}
	printf ("%d\n",ans.size());
	for (auto &p : ans) printf ("%d %d\n",p.first,p.second);
    return 0;
}