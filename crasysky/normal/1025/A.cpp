#include <iostream>
#include <cstdio>
using namespace std;
string s;
int cnt[1000006];
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch&& ch <= '9'){
		cnt = cnt * 10 + ch- '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read();
	if  (n ==1 ){
		cout << "Yes" << endl;
		return  0;
	}
	cin >> s;
	for (int i = 0; i < n; ++ i)
		cnt[s[i] - 'a' + 1] ++;
	bool have = false;
	for (int i = 1; i <= 26; ++ i)
		if (cnt[i] >= 2)
			have = true;
	if (have)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}