#include<iostream>
#include<string>
#include<set>

using namespace std;

set<char>	st;

int main(){
	string s;
	getline(cin, s);
	for (int i = 1; i < (int)s.size(); i += 3)
		if (s[i] >= 'a' && s[i] <= 'z')
			st.insert(s[i]);
	cout << st.size() << endl;
	return	0;
}