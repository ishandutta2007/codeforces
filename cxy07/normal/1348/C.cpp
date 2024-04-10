//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,n,k,now;
int cnt[30];
char s[MAXN];
bool flag;

signed main () {
	cin >> T;
	while(T--) {
		cin >> n >> k;
		cin >> s + 1;
		flag = true;
		memset(cnt,0,sizeof cnt);
		now = 0;
		sort(s + 1,s + n + 1);
		for(register int i = 1;i <= n; ++i) {
			if(i != 1 && s[i] != s[i - 1]) break;
			now++;
		}
		if(now < k) {cout << s[k] << endl; continue;}
		cout << s[1];
		now = 0;
		for(register int i = k + 1;i <= n; ++i) {
			cnt[s[i] - 'a']++;
			if(cnt[s[i] - 'a'] == 1) now++;
		}
		if(now == 1) {
			int lim = ceil((double)cnt[s[k + 1] - 'a'] / k);
			for(register int i = 1;i <= lim; ++i)
				cout << s[k + 1];
			cout << endl;
		} else {
			for(register int i = k + 1;i <= n; ++i)
				cout << s[i];
			cout << endl;
		}
	}
	return 0;
}