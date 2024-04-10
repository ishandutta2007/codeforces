#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n;
string s, t, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t; n = s.size();
	sort(s.begin(), s.end());
	s.resize(n+1>>1);
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	t.resize(n>>1);

	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	int i = 0;
	for (i = 0; i < n; i++)
		if (!(i&1)){
			if (t.empty() || s.back() < t.back())
				ans += s.back(), s.pop_back();
			else
				break;
		}
		else{
			if (s.empty() || s.back() < t.back())
				ans += t.back(), t.pop_back();
			else
				break;
		}

	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	string temp;
	for (; i < n; i++)
		if (!(i&1)){
			temp += s.back();
			s.pop_back();
		}
		else{
			temp += t.back();
			t.pop_back();
		}
	reverse(temp.begin(), temp.end());
	ans += temp;

	cout << ans << "\n";
	return 0;
}