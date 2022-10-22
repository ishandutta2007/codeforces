#include<iostream>
#include<string>

using namespace std;

const int max_n = 1e6 + 100;

string s;
int f[max_n];
bool mark[max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;

	int k = f[1] = 0, ans = -1;
	for (int i = 1; i < s.size(); i++){
		while (k && s[i] != s[k])	k = f[k];
		if (s[i] == s[k])	k++;
		f[i + 1] = k;
		if (i != s.size() - 1)	mark[k] = 1;
		else while (k){
			if (mark[k]){
				ans = k;
				break;
			}		
			else	k = f[k];		
		}
	}
	if (ans == -1){
		cout << "Just a legend" << endl;
		return 0;
	}
	for (int i = 0; i < ans; i++)
		cout << s[i];
	cout << endl;
	return 0;
}