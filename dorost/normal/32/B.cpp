#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '-' && s[i + 1] == '.'){
			i++;
			cout << '1';
		}else if (s[i] == '-' && s[i + 1] == '-'){
			i++;
			cout << 2;
		}else if (s[i] == '.'){
			cout << 0;
		}
	}
}