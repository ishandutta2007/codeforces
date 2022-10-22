#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, k;
string s;

int f(string a, string b){
	int t = 0;
	for (int i = 0; i < a.size(); i++)	
		if (a[i] != b[i])	t++;
	return	t;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> s;
	if (k == 2){
		string a = "", b = "";
		string temp = "AB";
		while (a.size() < n)	a += temp;
		temp = "BA";
		while (b.size() < n)	b += temp;
		a.resize(n);
		b.resize(n);
		if (f(a, s) < f(b,s))	cout << f(a, s) << "\n" << a << endl;
		else	cout << f(b,s) << "\n" << b << endl;
		return 0;
	}
	int t = 0;
	s += '#';
	for (int i = 1; i < n; i++){
		if (s[i - 1] != s[i])	continue;
		if (s[i] == s[i + 1] || s[i] == s[i - 1]){
			if (s[i - 1] != 'A' && s[i + 1] != 'A')	s[i] = 'A';
			else if (s[i - 1] != 'B' && s[i + 1] != 'B')	s[i] = 'B';
			else	s[i] = 'C';
			t++;
			i++;
		}
	}
	cout << t << endl;
	s.resize(n);
	cout << s << endl;
	return 0;
}