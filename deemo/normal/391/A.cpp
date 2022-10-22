#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;	
	string s;
	cin >> s;	n = s.size();
	int ans = 0;
	for (int i = 0; i < n; ){
		int j = i;
		while (s[i] == s[j])	j++;
		if ((j - i) % 2 == 0)
			ans++;
		i = j;
	}
	cout << ans << endl;
	return 0;
}