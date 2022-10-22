#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
string s;
int cnt[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	int k = 0, ans = 1e9;
	for (char c:s){
		cnt[c]++;
		if (cnt[c] == 1)	k++;
	}
	memset(cnt, 0, sizeof(cnt));
	int cur = 0, r = 0;
	for (int i = 0; i < n; i++){
		r = max(r, i);
		while (r < n && cur < k){
			cnt[s[r]]++;
			if (cnt[s[r]] == 1)
				cur++;
			r++;
		}

		if (r == n && cur != k)	break;
		ans = min(ans, r - i);
		cnt[s[i]]--;
		if (cnt[s[i]] == 0)	cur--;
	}
	cout << ans << endl;
	return 0;
}