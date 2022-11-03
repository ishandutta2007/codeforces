#include <bits/stdc++.h>
   
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

struct tree{
	int last;
	int suf[1000007];
	int link[1000007];
	int len[1000007];
	int diff[1000007];
	int to[1000007][26];
	int sz;
	vector<int> s;

	tree() { s.pub(-1); sz = 2; last = 1; for (int i = 0; i < 1000007; i++) suf[i] = -1, len[i] = -1, link[i] = -1; len[1] = 0; suf[1] = 0; for (int i = 0; i < 1000007; i++) for (int j = 0; j < 26; j++) to[i][j] = -1; }

	void add(int c){
		s.pub(c);
		while(last != -1){
			if (c != s[(int)s.size() - len[last] - 2]) last = suf[last];
			else break;
		}
		if (to[last][c] == -1){
			int v = sz++;
			to[last][c] = v;
			len[v] = len[last] + 2;
			do{
				last = suf[last];
			} while(last != -1 && c != s[(int)s.size() - len[last] - 2]);
			if (last == -1){
				suf[v] = 1;
			} else {
				suf[v] = to[last][c];
			}
			diff[v] = len[v] - len[suf[v]];
			if (diff[v] == diff[suf[v]])
				link[v] = link[suf[v]];
			else 
				link[v] = suf[v];
			last = v;
		} else last = to[last][c];
	}
} cc;

int series_ans[1000007];
int p_series_ans[1000007];
string s1, s2;
int dp[1000007];
int p[1000007];

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output2.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s1 >> s2;
	string s;
	for (int i = 0; i < s1.size() * 2; i++){
		if (i % 2 == 0){
			s += s1[i / 2];
		} else {
			s += s2[i / 2];
		}
	}

	dp[0] = 0;
	p[0] = -1;

	for (int i = 1; i <= s.size(); i++){
		cc.add(s[i - 1] - 'a');
		dp[i] = 1e9 + 7;
		p[i] = -1;

		if (i - 2 >= 0 && s[i - 1] == s[i - 2]){
			dp[i] = dp[i - 2];
			p[i] = i - 2;
		}
		for (int v = cc.last; v > 1; v = cc.link[v]){
			series_ans[v] = dp[i - (cc.len[cc.link[v]] + cc.diff[v])];
			p_series_ans[v] = i - (cc.len[cc.link[v]] + cc.diff[v]);
			if (cc.diff[v] == cc.diff[cc.suf[v]]){
				if (series_ans[cc.suf[v]] < series_ans[v]){
					series_ans[v] = series_ans[cc.suf[v]];
					p_series_ans[v] = p_series_ans[cc.suf[v]]; 
				}
			}
			//cout << "===" << v << ' ' << cc.len[v] << ' ' << series_ans[v] << endl;
			if (series_ans[v] + 1 < dp[i]){
				dp[i] = min(dp[i], series_ans[v] + 1);
				p[i] = p_series_ans[v];
			}
			/*if (dp[i - cc.len[v]] + 1 < dp[i]){
				dp[i] = dp[i - cc.len[v]] + 1;
				p[i] = i - cc.len[v];
			}*/
		}


		if (i % 2 == 1){
			dp[i] = 1e9 + 7;
			p[i] = -1;
		}
		//cout << i << ' ' << dp[i] << ' ' << p[i] << endl;
	}


	//exit(0);
	if (dp[s.size()] == 1e9 + 7) cout << -1, exit(0);

	vector<pair<int, int> > ans;

	int pos = s.size();

	while(pos != 0){
		int pred = p[pos];
		if (pred + 2 != pos){
			ans.pub(mp((pred + 2) / 2, pos / 2));
		}	
		pos = pred;
	}

	cout << ans.size() << endl;
	for (auto c : ans) cout << c.x << ' ' << c.y << "\n";
}