//Code By CXY
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 110;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,ans,now;
char s[MAXN];
int pre[MAXN],nxt[MAXN];

inline void Del(int x) {
	nxt[pre[x]] = nxt[x];
	pre[nxt[x]] = pre[x];
	ans++;
}

signed main () {
	cin >> n;
	cin >> s + 1;
	for(register int i = 1;i <= n; ++i)
		pre[i] = i - 1,nxt[i] = i + 1;
	nxt[0] = 1,pre[n + 1] = n;
	for(register int i = 25;i >= 0; --i) {
		for(register int p = 1;p <= 100; ++p) {
			now = nxt[0];
			while(now <= n) {
				int tmp = -1;
				if(s[now] - 'a' == i) {
					if(pre[now] >= 1 && abs(s[now] - s[pre[now]]) == 1) tmp = now;
					else if(nxt[now] <= n && abs(s[now] - s[nxt[now]]) == 1) tmp = now;
				}
				now = nxt[now];
				if(tmp != -1) Del(tmp);
			}
			now = pre[n + 1];
			while(now) {
				int tmp = -1;
				if(s[now] - 'a' == i) {
					if(pre[now] >= 1 && abs(s[now] - s[pre[now]]) == 1) tmp = now;
					else if(nxt[now] <= n && abs(s[now] - s[nxt[now]]) == 1) tmp = now;
				}
				now = pre[now];
				if(tmp != -1) Del(tmp);
			}
		}
	}
	cout << ans << endl;
	return 0;
}