#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	s += t;
	cout << s << endl;
	return 0;
}