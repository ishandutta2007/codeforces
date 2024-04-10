#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string f1(string s){
	string ret = "";
	int i = 1, t = 0;
	for (; i < s.size() && s[i] < 'A'; i++)	ret += s[i];
	i++;
	for (; i < s.size(); i++)
		t = t * 10 + int(s[i] - '0');

	while (t > 0){
		int z = t % 26;
		if (z == 0)	z = 26;
		
		ret = char('A' + (z - 1)) + ret;
		t /= 26;
		if (z == 26)	t--;
	}
	return	ret;
}

void f2(string s){
	string ret = "";
	int i = 0, t = 0;

	for (; i < s.size() && s[i] >= 'A'; i++)
		t = t * 26 + (s[i] - 'A' + 1);
	
	cout << "R";
	for (; i < s.size(); i++)
		cout << s[i];
	cout << "C";
	cout << t << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		string s;	cin >> s;
		int ind = 0;
		for (; ind < s.size(); ind++)
			if (s[ind] < 'A')	break;
		bool fl = 0;
		for (; ind < s.size(); ind++)
			if (s[ind] >= 'A')	fl = 1;

		if (fl)
			cout << f1(s) << "\n";
		else
			f2(s);
	}
	return	0;
}