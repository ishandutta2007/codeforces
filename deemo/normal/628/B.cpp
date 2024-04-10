#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;

	long long ans = 0;
	for (int i = 0; i < (int)s.size(); i++){
		int z = s[i] - '0';
		if (z % 4 == 0)	ans++;

		if (i != 0){
			z = z + (s[i - 1] - '0') * 10;
			if (z % 4 == 0)
				ans += i;
		}
	}
	cout << ans << "\n";
	return	0;
}