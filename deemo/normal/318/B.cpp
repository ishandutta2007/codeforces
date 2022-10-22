#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int MAX = 6e6;

bool mark[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	int cnt = 0;
	for (int i = 0; i + 4 < s.size(); i++)
		if (s[i] == 'h' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'v' && s[i + 4] == 'y'){
			mark[i + 4] = 1;
			cnt++;
		}

	long long ans = 0;
	for (int i = s.size() - 1; i - 4 >= 0; i--){
		if (s[i] == 'l' && s[i - 1] == 'a' && s[i - 2] == 't' && s[i - 3] == 'e' && s[i - 4] == 'm')
			ans += cnt;
		if (mark[i])	cnt--;
	}
	cout << ans << endl;
	return 0;	
}