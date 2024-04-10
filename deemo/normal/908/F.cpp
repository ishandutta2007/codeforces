#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int conv[400];
int n;
pii sec[MAXN];
ll a[3][MAXN], s[3];
ll ans = 0;

void trim() {
	int mn = a[0][0];
	for (int w = 1; w < 3; w++){ 
		int tt = 0;
		for (int i = 0; i < s[w]; i++)
			if (a[w][i] < mn) {
				ans += min(mn - a[w][i], i+1<s[w]?a[w][i+1]-a[w][i]:(int)2e9);
				tt++;
			}
			else
				break;
		for (int i = tt; i < s[w]; i++)
			a[w][i-tt] = a[w][i];
		s[w] -= tt;
	}
}

ll d[MAXN];
ll lst[4], z[4];

void smax(ll &x, ll y){ x = max(x, y);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	conv['G'] = 0;
	conv['B'] = 1;
	conv['R'] = 2;
	cin >> n;
	for (int i = 0; i < n; i++){
		int p; char ch; cin >> p >> ch;
		sec[i] = {p, conv[ch]};
		a[conv[ch]][s[conv[ch]]++] = p;
	}

	if (!s[0]) {
		for (int w = 1; w < 3; w++)
			if (s[w])
				ans += a[w][s[w] - 1] - a[w][0];
	}
	else{
		trim();
		for (int w = 0; w < 3; w++) {
			for (int i = 0; i < s[w]; i++)
				a[w][i] = -a[w][i];
			reverse(a[w], a[w] + s[w]);
		}
		trim();
		for (int w = 0; w < 3; w++) {
			for (int i = 0; i < s[w]; i++)
				a[w][i] = -a[w][i];
			reverse(a[w], a[w] + s[w]);
		}

		memset(d, 63, sizeof(d));
		d[0] = 0;
		int cur = 0;
		for (int i = 1; i < s[0]; i++) {
			d[i] = d[i-1] + 2ll*(a[0][i] - a[0][i-1]);

			while (sec[cur].F <= a[0][i-1]) cur++;
			lst[1] = lst[2] = a[0][i-1];
			z[1] = z[2] = -1;
			while (sec[cur].F < a[0][i]) {
				smax(z[sec[cur].S], sec[cur].F - lst[sec[cur].S]);
				lst[sec[cur].S] = sec[cur].F;
				cur++;
			}
			for (int w = 1; w < 3; w++)
				smax(z[w], a[0][i] - lst[w]);
			d[i] = min(d[i], d[i-1] + 3ll*(a[0][i] - a[0][i-1]) - z[1] - z[2]);
		}
		ans += d[s[0]-1];
	}
	cout << ans << "\n";
	return 0;
}