#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	string s;	cin >> s;
	int x;	cin >> x;

	for (int i = 0; i < s.size(); i++){
		if (s[i] < 'a')
			s[i] += 'a' - 'A';

		if (s[i] < x + 97){
			if (s[i] > 'Z')s[i] -= 'a' - 'A';	
		}
		else
			if (s[i] < 'a')	s[i] += 'a' - 'A';

	}

	cout << s << endl;
	return 0;
}