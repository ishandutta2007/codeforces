#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector<int> vl, vu, vd;
		for(int i=0;i<s.size();i++) {
			if('a' <= s[i] && s[i] <= 'z') {
				vl.push_back(i);
			} else if('A' <= s[i] && s[i] <= 'Z') {
				vu.push_back(i);
			}  else {
				vd.push_back(i);
			}
		}
		int l = vl.size(), u = vu.size(), d = vd.size();
		if(l && u && d) {
			cout << s << endl;
		} else if(l && u) {
			if(l > 1) {
				s[vl[0]] = '0';
				cout << s << endl;
			} else {
				s[vu[0]] = '0';
				cout << s << endl;
			}
		} else if(l && d) {
			if(l > 1) {
				s[vl[0]] = 'A';
				cout << s << endl;
			} else {
				s[vd[0]] = 'A';
				cout << s << endl;
			}
		}
		else if(u && d) {
			if(u > 1) {
				s[vu[0]] = 'a';
				cout << s << endl;
			} else {
				s[vd[0]] = 'a';
				cout << s << endl;
			}
		} else if(l) {
			s[0] = '0';
			s[1] = 'A';
			cout << s << endl;
		}else if(u) {
			s[0] = '0';
			s[1] = 'a';
			cout << s << endl;
		}else{
			s[0] = 'a';
			s[1] = 'A';
			cout << s << endl;
		}
	}
}