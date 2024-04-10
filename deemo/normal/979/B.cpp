#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int n;
string s[3];
int cnt[400], mx[3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int w = 0; w < 3; w++){
		cin >> s[w];
		memset(cnt, 0, sizeof(cnt));
		for (char c:s[w])
			mx[w] = max(mx[w], ++cnt[c]);
		
		int rem = n, t = (int)s[w].size() - mx[w];
		if (mx[w] == s[w].size() && rem == 1)
			mx[w]--;
		else {
			int g = min(rem, t);
			mx[w] += g;
			rem -= g;
		}
	}
	int ans = 0, cnt = 0;
	for (int w = 0; w < 3; w++)
		if (mx[w] == ans)
			cnt++;
		else
			if (mx[w] > ans)
				ans = mx[w], cnt = 1;
	if (cnt > 1)
		cout << "Draw\n";
	else{
		if (mx[0] == ans)
			cout << "Kuro\n";
		else if (mx[1] == ans)
			cout << "Shiro\n";
		else
			cout << "Katie\n";
	}
	return 0;
}