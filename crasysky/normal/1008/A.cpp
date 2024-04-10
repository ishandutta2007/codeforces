#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.length();
	bool flag = false;
	for (int i = 0; i < n; ++ i)
		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'n'){
			if (i == n - 1 || s[i + 1] != 'a' && s[i + 1] != 'e' && s[i + 1] != 'i' && s[i + 1] != 'o' && s[i + 1] != 'u'){
				flag = true;
				break;
			}
		}
	if (flag)
		cout << "NO";
	else
		cout << "YES";
}