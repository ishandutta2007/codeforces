#include<iostream>
#include<string>

using namespace std;

int m[200];

int main(){
	string s;	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++){
		m[s[i]]++;
		if (m[s[i]] % 2 == 1)	cnt++;
		else	cnt--;
	}
	if (cnt == 0 || cnt == 1){
		cout << "First\n";
		return 0;
	}

	if (cnt % 2 == 1)
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}