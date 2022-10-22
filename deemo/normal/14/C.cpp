#include<bits/stdc++.h>

using namespace std;

#define FAIL {cout << "NO\n"; return 0;}

int x[4];
map<pair<int, int>, int>	mp;

int main(){
	int t=4, c1=0, c2=0;
	while (t--){
		for (int i = 0; i < 4; i++)	cin >> x[i];
		if (x[0] != x[2] && x[1] != x[3])	FAIL
		if (x[0] == x[2] && x[1] == x[3])	FAIL
		if (x[0] == x[2])	c1++;
		if (x[1] == x[3])	c2++;
		mp[{x[0], x[1]}]++;
		mp[{x[2], x[3]}]++;
	}
	if (c1^c2)	FAIL
	for (auto z:mp)
		if (z.second ^ 2)	FAIL
	cout << "YES\n";
	return 0;
}