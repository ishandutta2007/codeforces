#include <iostream>
#include <cstdio>
using namespace std;
string s, t;
int main(){
	int T;
	cin >> T;
	while (T --){
		cin >> s >> t;
		bool flag = false;
		int j = 0;
		for (int i = 0; i < s.length(); ++ i){
			while (s[i] != t[j] && i && s[i - 1] == t[j] && j < t.length())
				++ j;
			if (j == t.length() || s[i] != t[j]){
				flag = true;
				cout << "NO" << endl;
				break;
			}
			++ j;
		}
		if (! flag)
			while (j < t.length()){
				if (s[s.length() -  1] != t[j]){
					flag = true;
					cout << "NO" << endl;
					break;
				}
				++ j;
			}
		if (! flag)
			cout << "YES" << endl;
	}
}