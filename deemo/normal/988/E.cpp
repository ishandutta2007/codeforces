#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int lst[20];
string s;

int get(int a, int b){
	int ret = a + max(0, (b + int(b < a))-1);
	return ret;
}

int f(int x, int y){
	if (x < y) swap(x, y);
	if (x == (int)s.size()-1){
		for (int i = 1; i < s.size(); i++)
			if (s[i] != '0' && ((int)s.size()-i) != y){
				return i-1;
			}
		return 1e9;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	memset(lst, -1, sizeof(lst));
	for (int i = (int)s.size()-1; ~i; i--)
		if (lst[s[i]-'0'] == -1)
			lst[s[i]-'0'] = (int)s.size()-1-i;

	int ans = 1e9;
	if (lst[0] != -1 && lst[5] != -1)
		ans = min(ans, get(lst[0], lst[5]));
	if (lst[7] != -1 && lst[5] != -1)
		ans = min(ans, get(lst[5], lst[7])+f(lst[7], lst[5]));
	if (lst[2] != -1 && lst[5] != -1)
		ans = min(ans, get(lst[5], lst[2])+f(lst[2], lst[5]));
	{
		int c = 0;
		for (char ch:s)
			if (ch == '0')
				c++;
		if (c >= 2){
			int ret = 0;
			c = 2;
			for (int i = (int)s.size()-1; ~i; i--)
				if (s[i] == '0'){
					ret += (int)s.size()-1-i;
					c--;
					if (c == 0) break;
				}
			ret--;
			ans = min(ans, ret);
		}
	}

	if (ans > 1e8)
		ans = -1;
	cout << ans << "\n";
	return 0;
}