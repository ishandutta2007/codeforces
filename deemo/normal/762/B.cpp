#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 4e5 + 10;

int a, b, c, n;
int sec[MAXN], gec[MAXN], sz1, sz2;
ll p1[MAXN], p2[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> n;
	while (n--){
		int val;	string s;
		cin >> val >> s;
		if (s[0] == 'U')
			sec[sz1++] = val;
		else
			gec[sz2++] = val;
	}
	sort(sec, sec + sz1);
	for (int i = 0; i < sz1; i++) p1[i + 1] = p1[i] + sec[i];
	sort(gec, gec + sz2);
	for (int i = 0; i < sz2; i++) p2[i + 1] = p2[i] + gec[i];

	int mx = 0;
	for (int i = 0; i <= c && i <= sz1; i++)
		mx = max(mx, min(i+a, sz1)+min(c-i+b, sz2));

	ll mn = 1e18;
	for (int i = 0; i <= c && i <= sz1; i++)
		if (min(i+a, sz1) + min(c-i+b, sz2) == mx){
			mn = min(mn, p1[min(i+a, sz1)] + p2[min(c-i+b, sz2)]);
		}
	cout << mx << " " << mn << endl;
	return 0;
}