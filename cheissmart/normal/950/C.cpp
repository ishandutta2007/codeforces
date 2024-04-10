#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	set<int> a[2];
	string s;
	vector<vector<int>> ans;
	cin >> s;
	for(int i=0;i<s.size();i++) 
		a[s[i]-'0'].insert(i);
	for(int i=0;i<s.size();i++) {
		if(!a[s[i]-'0'].count(i))
			continue;
		if(s[i] == '1') {
			cout << -1 << endl;
			return 0;
		}
		if(s[i] == '0') {
			vector<int> nw;
			nw.push_back(i);
			bool sw = 1;
			while(true) {
				auto ptr = a[sw].upper_bound(nw.back());
				if(ptr!= a[sw].end()) {
					nw.push_back(*ptr);
					a[sw].erase(ptr);
				} else break;
				sw = !sw;
			}
			if(sw == 0) {
				cout << -1 << endl;
				return 0;
			}
			ans.push_back(nw);
		}
	}
	cout << ans.size() << endl;
	for(auto &sth:ans) {
		cout << sth.size();
		for(auto sth_in_sth:sth) cout << " " << sth_in_sth+1;
		cout << endl;
	}
}