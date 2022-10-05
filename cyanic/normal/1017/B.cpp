#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 100005;
char s[maxn], t[maxn];
ll c00, c01, c10, c11, ans;
int n;

int main() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	rep (i, 1, n)
		if (s[i] == '0' && t[i] == '0') c00++;
		else if (s[i] == '0' && t[i] == '1') c01++;
		else if (s[i] == '1' && t[i] == '0') c10++;
		else c11++;
	
	ans += c00 * c10;
	ans += c00 * c11;
	ans += c01 * c10;
	ans += c10 * c00;
	ans += c10 * c01;
	ans += c11 * c00;
	
	cout << ans / 2 << endl;
	
	return 0;
}