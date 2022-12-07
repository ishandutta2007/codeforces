#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
string name[110];
vector<int> g[26];
int du[26];
int res[26];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> name[i];
	bool flag = 1;
	for(int i = 0; i < n - 1; ++i)
		for(int j = i + 1; j < n; ++j){
			int k;
			for(k = 0; k < name[i].size() && k < name[j].size(); ++k){
				if(name[i][k] != name[j][k]){
					g[name[i][k] - 'a'].pb(name[j][k] - 'a');
					++du[name[j][k] - 'a'];
					break;
				}
			}
			if(k == name[j].size()) flag = 0;
		}
	queue<int> q;
	for(int i = 0; i < 26; ++i)
		if(!du[i]) q.push(i);
	int tot = 0;
	while(!q.empty()){
		int t = q.front(); q.pop();
		res[tot++] = t;
		for(int v : g[t])
			if(!(--du[v])) q.push(v);
	}
	if(tot == 26 && flag)
		for(int i = 0; i < 26; ++i) cout << char('a' + res[i]);
	else
		cout << "Impossible";
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}