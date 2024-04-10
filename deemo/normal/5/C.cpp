#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const ll MAX = 1e6 + 20;
const int LOG = 30;

string s;
vector<int>	vec;
vector<pair<int, int>>	tt;
int nex[MAX];
vector<int>	sec[MAX];
int h[MAX], v[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	
	h[0] = 0;
	sec[0].push_back(0);
	v[0] = 1;
	for (int i = 0; i < s.size(); i++){
		if (vec.empty() || (s[i] == ')' && vec.back() == ')') || s[i] == '(')
			vec.push_back(s[i]);
		else	vec.pop_back();
		h[i + 1] = vec.size();
		sec[h[i + 1]].push_back(i + 1);
		v[i + 1] = sec[h[i + 1]].size();
	}

	nex[s.size()] = s.size() + 1;
	tt.push_back({h[s.size()], s.size()});
	for (int i = s.size() - 1; i >= 0; i--){
		while (tt.size() && tt.back().first >= h[i])
			tt.pop_back();
		if (tt.size() == 0)	nex[i] = s.size() + 1;
		else	nex[i] = tt.back().second;
		tt.push_back({h[i], i});
	}
	
	int ans = 0, cnt = 1;
	for (int i = 0; i <= s.size(); i++){
		int t = h[i], ind = v[i];
		int pos = lower_bound(sec[t].begin(), sec[t].end(), nex[i]) - sec[t].begin();
		if (pos - ind < 1)	continue;
		pos--, ind--;
		int temp = sec[t][pos] - sec[t][ind];	
		if (temp > ans){
			ans = temp;
			cnt = 1;
		}
		else if (temp == ans)	cnt++;
	}
	if (ans == 0)	cnt = 1;
	cout << ans << " " << cnt << endl;
	return 0;
}