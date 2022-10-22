#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	bool fl = 0;
	while (s.size()){
		if (s.size() > 2 && s[0] == '1' && s[1] == '4' && s[2] == '4'){
			string temp = "";
			for (int j = 3; j < s.size(); j++)
				temp += s[j];
			s = temp;
		}
		else if (s.size() > 1 && s[0] == '1' && s[1] == '4'){
			string temp = "";
			for (int j = 2; j < s.size(); j++)
				temp += s[j];
			s = temp;
		}
		else if (s.size() > 0 && s[0] == '1'){
			string temp = "";
			for (int j = 1; j < s.size(); j++)
				temp += s[j];
			s = temp;
		}
		else{
			fl = 1;
			break;
		}
	}

	if (fl){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;	
}