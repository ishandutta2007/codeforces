//Here we are, don't turn away now..

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[20];
ll d[17][2][2];
ll get(string r){
	int sz = 0;
	for (int i = 0; i < r.size(); i++)
		if (r[i] < 'a') a[sz++] = int(r[i]-'0');
		else a[sz++] = 10 + int(r[i] - 'a');

	ll ret = 1;
	for (int mx = 1; mx < 16; mx++){
		memset(d, 0, sizeof(d));
		d[0][0][0] = 1;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j <= mx; j++){
				ll temp = 1ll*j<<(sz-i-1)*4;
				if (temp>>mx&1) continue;

				if (j == mx)
					d[i + 1][1][1] += d[i][1][0];
				else
					d[i + 1][1][0] += d[i][1][0];
				d[i + 1][1][1] += d[i][1][1];

				if (j < a[i]){
					if (j == mx)
						d[i + 1][1][1] += d[i][0][0];
					else
						d[i + 1][1][0] += d[i][0][0];
					d[i + 1][1][1] += d[i][0][1];
				}
				else if (j == a[i]){
					if (j == mx)
						d[i + 1][0][1] += d[i][0][0];
					else
						d[i + 1][0][0] += d[i][0][0];
					d[i + 1][0][1] += d[i][0][1];
				}
			}
		ret += d[sz][0][1] + d[sz][1][1];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		string l, r; cin >> l >> r;
		ll ans = -get(r);

		bool fl = 0;
		if (l != "0"){
			for (int i = (int)l.size() - 1; ~i; i--)
				if (l[i] != '0'){
					if (l[i] == 'a') l[i] = '9';
					else l[i]--;

					for (int j = i+1; j < l.size(); j++) l[j] = 'f';
					break;
				}
			ans += get(l);
		}
		else fl = 1;
		{
			ll tr = 0, cur = 1;
			while (r.size()){
				if (r.back() < 'a')
					tr += cur*(int)(r.back()-'0');
				else
					tr += cur*(int)(10+r.back()-'a');
				cur *= 16ll;
				r.pop_back();
			}
			ll tl = 0; cur = 1;
			if (fl)
				tl = -1ll;
			else{
				while (l.size()){
					if (l.back() < 'a')
						tl += cur*(int)(l.back()-'0');
					else
						tl += cur*(int)(10+l.back()-'a');
					cur *= 16ll;
					l.pop_back();
				}
			}
			ans += tr - tl;
		}
		cout << ans << "\n";
	}
	return 0;
}