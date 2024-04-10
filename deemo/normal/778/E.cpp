#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3;

int n, beg, val[11], sec[MAXN], sc[MAXN], cc[11], gg[50];
string s[MAXN + 5], t;
ll d[MAXN+5][MAXN+5];

string gen(int x){
	string ret;
	while (x--) ret += '0';
	return ret;
}

void smax(ll &x, ll y){x = max(x, y);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t; 
	beg = MAXN - t.size(); t = gen(MAXN - t.size()) + t;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (char &c:s[i]) c++;
		s[i] = gen(MAXN - s[i].size()) + s[i];
	}
	for (int i = 1; i < 11; i++)	cin >> val[i];

	for (int i = 1; i < 30; i++) gg[i] = (i-1)%10+1;
	memset(d, -40, sizeof(d));
	d[MAXN][0] = 0;
	iota(sec, sec + n, 0);
	for (int w = MAXN - 1; ~w; w--){
		memset(cc, 0, sizeof(cc));
		for (int i = 0; i < n; i++) cc[max(0, (int)(s[i][w]-'0')-1)]++;
		for (int i = 1; i < 11; i++) cc[i] += cc[i - 1];
		for (int i = n-1; ~i; i--) sc[--cc[max(0, (int)(s[sec[i]][w]-'0')-1)]] = sec[i];
		for (int i = 0; i < n; i++) swap(sec[i], sc[i]);

		memset(cc, 0, sizeof(cc));
		for (int i = 0; i < n; i++) cc[s[i][w]-'0']++;
		
		int cur = 0;
		for (int j = 0; j <= n; j++){
			for (int c = 0; c < 10; c++)
				if (t[w] == char(c + '0') || (t[w] == '?' && (c > 0 || beg<w))){
					ll ret = d[w+1][j];
					int t = 0;
					for (int z = 1; z < 11; z++){
						ret += val[gg[z+c]]*cc[z];
						if (z+c > 10) t += cc[z];
					}
					if (c||beg<w)
						ret += val[1+c]*cc[0];
					smax(d[w][t+cur], ret);
				}

			if (j < n){
				int v = sc[n - 1 - j];
				cc[s[v][w]-'0']--;
				if (s[v][w]-'0' == 10){
					cur++;
					cc[1]++;
				}
				else{
					if (s[v][w] == '0')
						cc[2]++;
					else
						cc[s[v][w]-'0'+1]++;
				}
			}
		}
	}
	
	ll ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, d[0][i] + val[2]*i);
	cout << ans << "\n";
	return 0;
}