#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, k, sec[MAXN], sz, a[MAXN], mark[MAXN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++){
		if (s[i] == '(')
			sec[sz++] = i;
		else
			a[sec[--sz]] = i;
	}

	for (int i = 0; i < n && k; i++)
		if (s[i] == '('){
			mark[i] = mark[a[i]] = 1;
			k -= 2;
		}

	string ans;
	for (int i = 0; i < n; i++)
		if (mark[i])
			ans += s[i];
	cout << ans << "\n";
	return 0;
}