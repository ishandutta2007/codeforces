#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<utility>
#include<vector>
#include<cassert>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 1e5 + 10;

int n, sz, gg;
string s[MAXN], t[MAXN], ts[MAXN];
pair<string, ll>	sec[MAXN], gec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	{
		cin >> n;
		for (ll i = 0; i < n; i++){
			cin >> s[i];
			s[i] += '$';
			s[i] = s[i].substr(7);
		}
		sort(s, s + n);
		n = unique(s, s + n) - s;
	
		for (int i = 0; i < n; i++){
			for (int j = 0; j < s[i].size() && s[i][j] != '/' && s[i][j] != '$'; j++)
				t[i] += s[i][j];
			gec[i] = {t[i], i};
		}
		sort(gec, gec + n);

		for (int i = 0; i < n;){
			int j = i+1;
			ts[i] = s[gec[i].S].substr(t[gec[i].S].size());
			while (j < n && gec[j-1].F == gec[j].F)
				ts[i] += s[gec[j].S].substr(t[gec[j].S].size()), j++;
			sec[sz++] = {ts[i], i};
			i = j;
		}
		sort(sec, sec + sz);
		for (int i = 0; i < sz;){
			int j = i + 1;
			while (j < sz && sec[j-1].F == sec[j].F)	j++;
			if (j - i > 1)
				gg++;
			i = j;
		}
		cout << gg << "\n";
		for (int i = 0; i < sz;){
			int j = i+1;
			while (j < sz && sec[j-1].F == sec[j].F)	j++;
			if (j - i > 1){
				for (int w = i; w < j; w++)
					cout << "http://" << t[gec[sec[w].S].S] << " ";
				cout << "\n";
			}
			i = j;
		}
	}
	return	0;
}