#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int main(){
	int n;
	string s;
	cin >> n >> s;
	bool fl = 1;
	while (fl){
		fl = 0;
		for (int i = 0; i + 2 < s.size(); i++)
			if (s.substr(i, 3) == "ogo"){
				fl = 1;
				int j = i+3;
				s[i] = s[i + 1] = s[i + 2] = '*';
				while (j+2 <= s.size() && s[j] == 'g' && s[j + 1] == 'o'){
					s.erase(s.begin() + j);
					s.erase(s.begin() + j);
				}
				break;
			}
	}
	cout << s << endl;
	return 0;
}