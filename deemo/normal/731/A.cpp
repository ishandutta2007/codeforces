#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;

int main(){
	string s;
	cin >> s;
	int ans = 0;
	char cur = 'a';
	for (char ch:s){
		int temp = abs((int) cur - (int)ch);
		ans += min(temp, 26 - temp);
		cur = ch;
	}
	cout << ans << endl;
	return 0;
}