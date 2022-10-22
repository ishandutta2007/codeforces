#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	string s;	cin >> s;
	vector<int>	vec(n);
	for (int i = 0; i < n; i++)	cin >> vec[i];
	int pos = 0;
	for (int i = 0; i < n + 3; i++){
		if (s[pos] == '<')
			pos -= vec[pos];
		else
			pos += vec[pos];
		if (pos < 0 || pos >= n){
			cout << "FINITE\n";
			return 0;
		}
	}
	cout << "INFINITE\n";
	return 0;
}