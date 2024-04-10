#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 200;

int n;
string s;
vector<char>	st;
int tp[500], mark[500];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	tp['{'] = tp['}'] = 1;
	tp['['] = tp[']'] = 2;
	tp['('] = tp[')'] = 3;
	mark['{'] = mark['['] = mark['('] = mark['<'] = 1;

	int ans = 0;
	for (int i = 0; i < n; i++){
		int z = mark[s[i]];
		if (z == 1)
			st.push_back(s[i]);
		else{
			if (st.empty()){
				cout << "Impossible\n";
				return 0;
			}
			if (tp[s[i]] != tp[st.back()])
				ans++;
			st.pop_back();
		}
	}
	if (st.size()){
		cout << "Impossible\n";
		return 0;
	}
	cout << ans << endl;
	return 0;
}