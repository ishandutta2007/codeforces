#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	string s;	cin >> s;
	string a = "", b = "", c = "";
	if (s[0] == 'f'){
		a = "ftp";
		string t = s;
		s = "";
		for (int i = 3; i < t.size(); i++)
			s += t[i];
	}
	else{
		a = "http";
		string t = s;
		s = "";
		for (int i = 4; i < t.size(); i++)
			s += t[i];
	}
	
	int i;
	for (i = 0; i < s.size(); i++)
		if (i != 0 && s[i] == 'r' && s[i + 1] == 'u')
			break;
		else
			b += s[i];
	
	i++;
	i++;
	for (; i < s.size(); i++)
		c += s[i];

	if (c == ""){
		cout << a << "://" << b << ".ru";
		return	0;
	}
	cout << a << "://" << b << ".ru" << "/" << c << endl;
		
	return 0;
}