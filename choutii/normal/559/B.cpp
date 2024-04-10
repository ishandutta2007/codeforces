#include<bits/stdc++.h>

using namespace std;

const int MaxN = 501234;

int T; 
string s, t;
string trans(string t) {
	if(t.size() & 1) return t;
	string qL = trans(t.substr(0, t.size()/2));
	string qR = trans(t.substr(t.size()/2, t.size()));
	return qL < qR ? qL + qR : qR + qL;
}

int main() {
	cin >> s >> t;
	s = trans(s);
	t = trans(t);
	puts(s == t ? "YES" : "NO");
	return 0;	
}