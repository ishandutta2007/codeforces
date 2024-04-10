#include <bits/stdc++.h>
using namespace std;

string s,f[] = {"Danil","Olya","Slava","Ann","Nikita"}; 

int main() {
	cin >> s;
	int occ = 0;
	for(int i = 0; i < s.size(); ++i) {
		for(auto &t : f) {
			if(i+t.size() > s.size()) continue;
			occ += s.substr(i,t.size()) == t;
		}
	}
	cout << ((occ==1)?"YES\n":"NO\n");
}