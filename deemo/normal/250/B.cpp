#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
	int q;	cin >> q;
	while (q--){
		string	s;	cin >> s;
		int c = 0;
		for (int i = 0; i < (int)s.size(); i++)
			if (s[i] != ':' && (i == 0 || s[i - 1] == ':'))	c++;

		int rem = 8 - c;
		string t = "", ans = "";
		for (int i = 0; i < (int)s.size(); i++){
			if (s[i] == ':'){
				if (i != 0 && s[i - 1] == ':')
					for (int w = 0; w < rem; w++)
						ans += "0000:";
				else if((int)t.size()){
					while ((int)t.size() != 4)
						t = "0" + t;
					ans += t + ":";
				}
				t = "";
			}
			else	t += s[i];
		}	
		if (int(t.size())){
			while ((int)t.size() < 4)
				t = "0" + t;
			ans += t + ":";
		}
		ans.pop_back();
		cout << ans << endl;
	}
	return	0;
}