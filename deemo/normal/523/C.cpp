#include<iostream>
#include<string>

using namespace std;

string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int i1 = 0, cur = 0;
	for (; i1 < t.size(); i1++){
		if (s[cur] == t[i1])	cur++;
		if (cur == s.size())	break;
	}
	
	int i2 = t.size() - 1;	cur = s.size() - 1;
	for (; i2 >= 0; i2--){
		if (s[cur] == t[i2])	cur--;
		if (cur < 0)	break;
	}

	cout << max(0, i2 - i1) << "\n";
	return	0;
}