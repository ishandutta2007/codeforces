#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll m, val[20];
vector<ll>	vec[3];
bool c[10][10];
map<string, ll>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp["Anka"] = 0;
	mp["Chapay"] = 1;
	mp["Cleo"] = 2;
	mp["Troll"] = 3;
	mp["Dracul"] = 4;
	mp["Snowy"] = 5;
	mp["Hexadecimal"] = 6;
	cin >> m;
	while (m--){
		string a, b, temp;
		cin >> a >> temp >> b;
		c[mp[a]][mp[b]] = 1;
	}
	for (ll i = 0; i < 3; i++)	cin >> val[i];

	ll mn = 1e12, cnt = -1;
	for (ll i = 0; i < (1<<7); i++)
		for (ll j = i; 1; j = (j - 1) & i){
			for (ll w = 0; w < 3; w++)	vec[w].clear();
			for (ll w = 0; w < 7; w++){
				if (!((i >> w) & 1))	vec[0].push_back(w);
				else if (!((j >> w) & 1))	vec[1].push_back(w);
				else	vec[2].push_back(w);
			}
			
			bool fail = 0;
			ll smn = 1e12, smx = -1e12;
			ll cc = 0;
			for (ll w = 0; w < 3; w++){
				if (vec[w].empty()){
					fail = 1;
					break;
				}
				for (ll ii = 0; ii < vec[w].size(); ii++)
					for (ll jj = 0; jj < vec[w].size(); jj++)
						if (ii != jj)
							if (c[vec[w][ii]][vec[w][jj]])	cc++;
				smn = min(smn, val[w]/ (ll)vec[w].size());
				smx = max(smx, val[w]/ (ll)vec[w].size());
			}
			if (!fail){
				smn = smx - smn;
				if (smn < mn){
					mn = smn;
					cnt = cc;
				}
				else if (smn == mn)
					cnt = max(cnt, cc);
			}
			if (j == 0)	break;
		}
	cout << mn << " " << cnt << "\n";
	return	0;
}