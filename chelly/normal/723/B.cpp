#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string st, cur;
	cin >> st;
	int inp(0);
	int ans1(0), ans2(0);
	st.push_back('(');
	for(int i(0); i < (int)st.size(); i++) {
		if(st[i] == '_' || st[i] == '(' || st[i] == ')') {
			if(!cur.empty()) {
				if(inp) {
					ans2++;
				}else {
					ans1 = max(ans1, (int)cur.size());
				}
				cur.clear();
			}
			if(st[i] == '(') {
				inp = true;
			}else if(st[i] == ')') {
				inp = false;
			}
		}else {
			cur.push_back(st[i]);
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
}