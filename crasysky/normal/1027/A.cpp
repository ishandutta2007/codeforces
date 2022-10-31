#include <iostream>
#include <cstdio>
using namespace std;
string s;
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int aabs(int x){
	return x >= 0 ? x : -x;
}
int main(){
	int T = read();
	while (T --){
		int n = read();
		cin >> s;
		bool flag = false;
		for (int i = 0; i < n; ++ i){
			int j = n - i - 1;
			if (aabs(s[i] - s[j]) == 1 || aabs(s[i] - s[j]) > 2){
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}