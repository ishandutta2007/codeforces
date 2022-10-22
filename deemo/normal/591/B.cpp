#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

char ss[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;	cin >> n >> m;
	string s;	cin >> s;
	for (char c = 'a'; c <= 'z'; c++)
		ss[c] = c;

	while (m--){
		char a, b;	cin >> a >> b;
		swap(ss[a], ss[b]);
	}

	for (int i = 0; i < n; i++){
		for (char c = 'a'; c <= 'z'; c++)
			if (ss[c] == s[i]){
				s[i] = c;
				break;
			}
		cout << s[i];
	}
	cout << "\n";
	return	0;
}