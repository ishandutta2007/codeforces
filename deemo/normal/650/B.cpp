#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 5e5 + 20;

ll n, x, y, T, p[MAXN], sp[MAXN], p2[MAXN];
char ch[MAXN];
string s;

int main(){
	scanf("%I64d %I64d %I64d %I64d", &n, &x, &y, &T);
	scanf("%s", ch);
	s = ch;
	
	for (ll i = 0; i < n; i++){
		if (s[i] == 'h')
			p[i + 1] = p[i];
		else
			p[i + 1] = p[i] + 1;
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++){
		ll ret = i * x + p[i + 1] * y + (i + 1);
		if (ret > T)	continue;
		ans = max(ans, i + 1);
		
		ll b = i + 1, e = n - 1, rt = n;
		while (b <= e){
			ll mid = (b + e)/ 2;
			if (ret + i * x + (p[n] - p[mid]) * y + (n - mid) + (n - mid) * x <= T)
				rt = mid, e = mid - 1;
			else
				b = mid + 1;
		}
		ans = max(ans, i + 1 + (n - rt));
	}

	if (n > 1){
		for (ll i = n - 1; i; i--){
			ll ret = (n - i + 1) + (n - i) * x + (p[n] - p[i] + int(s[0] != 'h')) * y;
			if (ret > T)	continue;
			ans = max(ans, n - i + 1);

			ll b = 1, e = i - 1, rt = 0;
			while (b <= e){
				ll mid = (b + e)/ 2;
				if (ret + (n - i + mid) * x + (p[mid + 1] - int(s[0] != 'h')) * y + mid <= T)
					rt = mid, b = mid + 1;
				else
					e = mid - 1;
			}
			ans = max(ans, n - i + 1 + rt);
		}
	}

	printf("%I64d\n", ans);
	return	0;
}