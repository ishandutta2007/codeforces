#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int n, max = 0;
	string s;
	cin >> n >> s;
	char a, b;
	map <pair <char, char>, int> mp;
	for (int i = 1; i < n; i++){
		mp[{s[i], s[i - 1]}] ++;
		if(mp[{s[i], s[i - 1]}] > max){
			max = mp[{s[i], s[i - 1]}];
			a = s[i], b = s[i - 1];
		}
	}
	cout << b << a;
}