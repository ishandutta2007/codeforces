#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, p[MAXN];
string s[MAXN], t[MAXN], g[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i] >> t[i];
	for (int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	
	for (int i = 0; i < n; i++){
		if (i == 0)
			g[i] = min(s[p[i]], t[p[i]]);
		else{
			string temp = min(s[p[i]], t[p[i]]);
			if (temp < g[i - 1])
				temp = max(s[p[i]], t[p[i]]);

			if (temp < g[i - 1]){
				cout << "NO\n";
				return	0;
			}	
			g[i] = temp;
		}
	}
	cout << "YES\n";
	return	0;
}