#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 5e5 + 10;

ll n, p[MAXN];
ll a[MAXN], b[MAXN];
char ch[MAXN];
string s;

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++)
		scanf("%I64d", &p[i]);
	scanf("%s", ch);
	s = ch;
	for (ll i = 0; i <= n; i++){
		a[i + 1] = a[i] + p[i] * (s[i] == 'A');
		b[i + 1] = b[i] + p[i] * (s[i] == 'B');
	}

	ll ans = b[n];
	for (ll i = 0; i <= n; i++){
		ans = max(ans, a[i] + b[n] - b[i]);
		ans = max(ans, b[i] + a[n] - a[i]);
	}
	printf("%I64d\n", ans);
	return	0;
}