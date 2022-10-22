#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 100;

int n;
string s[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	int ind = 0;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		if (s[i] == "0"){
			cout << "0\n";
			return	0;	
		}

		int cnt = 0;
		for (char ch:s[i])
			if (ch == '1')	cnt++;
			else if (ch != '0')	cnt += 2;
		if (cnt > 1)	ind = i;
	}
	cout << s[ind];
	for (int i = 0; i < n; i++)
		if (i != ind)
			for (int j = 0; j < (int)s[i].size() - 1; j++)
				cout << "0";
	cout << "\n";
	return	0;	
}