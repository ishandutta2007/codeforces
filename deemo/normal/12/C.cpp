#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN = 100 + 10;

int n, m, vec[MAXN], sec[MAXN];
string s[MAXN];
map<string, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	for (int i = 0; i < m; i++)	cin >> s[i], mp[s[i]]++;
	sort(s, s + m);
	m = unique(s, s + m) - s;
	for (int i = 0; i < m; i++)
		sec[i] = mp[s[i]];
	sort(sec, sec + m);
	
	int x = 0, y = 0;
	for (int i = m - 1; i >= 0; i--)
		x += sec[i] * vec[m - i - 1];
	for (int i = 0; i < m; i++)
		y += sec[i] * vec[n - (m - i)];
	cout << x << " " << y << "\n";
	return	0;	
}