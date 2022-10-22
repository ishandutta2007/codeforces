#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int pw(int a, int b){
	int ret = 1;
	while (b--)
		ret = (ret * a) % 5;
	return	ret;
}

int main(){
	string s;	cin >> s;
	int z = 0;
	int n = s.size();
	for (int i = max(0, n - 2); i < s.size(); i++)
		z = (z * 10) + (s[i] - 48);

	int ans = 0;
	for (int i = 1; i < 5; i++)
		ans += pw(i, z);
	cout << ans % 5 << endl;
	return	0;
}