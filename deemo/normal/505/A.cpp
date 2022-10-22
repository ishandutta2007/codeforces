#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool ok(string s){
	string t = s;
	reverse(t.begin(), t.end());
	return	s == t;
}

int main(){
	string s;	cin >> s;
	int n = s.size();
	for (int i = 0; i <= n; i++)
		for (char c = 'a'; c <= 'z'; c++){
			string t = s;
			string g = "";	g += c;
			t.insert(i, g);
			if (ok(t)){
				cout << t << "\n";
				return	0;
			}
		}
	cout << "NA\n";
	return	0;
}