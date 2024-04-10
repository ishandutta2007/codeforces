//Who else is gonna put up with me this way..

#include<iostream>
#include<string>

using namespace std;

bool vis[200];
int ans;

int main(){
	int n;	cin >> n;
	if (n > 26){
		cout << "-1\n";
		return 0;
	}
	string s;	cin >> s;
	for (int i = 0; i < n; i++)
		if (vis[s[i]])	ans++;
		else	vis[s[i]] = 1;
	cout << ans << "\n";
	return 0;
}