//Code By CXY
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 1010;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,chk,L,R;
char s[MAXN];
vector<int> ans;

signed main () {
	cin >> s + 1;
	n = strlen(s + 1);
	L = 1,R = n;
	while(L < R) {
		while(L < R && s[L] != '(') L++;
		while(L < R && s[R] != ')') R--;
		if(L < R && s[L] == '(' && s[R] == ')') {
			ans.push_back(L);
			ans.push_back(R);
			L++,R--;
		}
	}
	if(!ans.size()) return puts("0"),0;
	puts("1");
	cout << ans.size() << endl;
	sort(ans.begin(),ans.end());
	for(register int i = 0;i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << endl;
	return 0; 
}