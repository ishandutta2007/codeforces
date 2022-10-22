#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	string s;	cin >> s;
	int k;	cin >> k;

	for (int i = 0; i < (int)s.size(); i++){
		int maxi = s[i] - '0', ind = i;
		for (int j = i + 1; j < i + k + 1 && j < (int)s.size(); j++)
			if (s[j] - '0' > maxi){
				maxi = s[j] - '0';
				ind = j;
			}
		if (maxi == s[i] - '0')	continue;

		k -= ind - i;
		for (int j = ind - 1; j >= i; j--)
			swap(s[j], s[j + 1]);
	}
	cout << s << endl;
	return 0;
}