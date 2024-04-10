#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 4e5 + 10;
const int C = 8;
const int D = 3;

int n, nxt[MAXN];
string s;
bool d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	d[n] = 1;
	for (int i = n - 1; ~i; i--)
		if (s[i] != '.'){
			int j = i + 1;
			while (j < n && j <= i + C && s[j] != '.')	j++;
			
			if (j >= n || j > i + C)	continue;
			
			for (int w = j + 1; w <= j + 3 && w < n && s[w] != '.'; w++)
				if (d[w + 1]){
					d[i] = 1;
					nxt[i] = w + 1;
					break;
				}
		}
	if (d[0]){
		cout << "YES\n";
		int cur = 0;
		while (cur < n){
			cout << s.substr(cur, nxt[cur] - cur) << "\n";
			cur = nxt[cur];
		}
	}
	else
		cout << "NO\n";
	return 0;
}