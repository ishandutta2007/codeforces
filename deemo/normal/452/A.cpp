#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

string ss[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(){
	int n;	cin >> n;
	string s;	cin >> s;
	for (int i = 0; i < 8; i++){
		int c = 0;
		if (n != ss[i].size())	continue;
		for (int j = 0; j < n; j++)
			if (s[j] == '.' || s[j] == ss[i][j])	c++;
		if (c == n){
			cout << ss[i] << endl;
			return	0;
		}
	}
	return	0;
}