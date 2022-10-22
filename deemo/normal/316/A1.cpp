#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

string s, ans;
bool mark[500];
ll ret = 1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int cnt = 0, cc = 0;
	for (char c:s){
		if (c == '?')	cnt++;
		else if ('A' <= c && c <= 'J'){
			if (!mark[c])	cc++;
			mark[c] = 1;
		}	
	}
	
	for (int i = 0; i < cc; i++){
		ll z = 10 - i;
		if (z == 10 && 'A' <= s[0] && s[0] <= 'J')	z = 9;
		ret *= z;
	}
	
	if (s[0] == '?'){
		cnt--;
		ret *= 9;
	}	
	
	cout << ret;
	while (cnt--)
		cout << "0";
	cout << "\n";
	return	0;
}