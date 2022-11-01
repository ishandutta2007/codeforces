#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n, m;

string a[105];

string b[105];

map <string, int> s[5];

int ans = 0;

int main(){
	int i, j;
	
	cin >> n;
	
	s[0]["M"] = 0;
	s[0]["L"] = 0;
	s[0]["S"] = 0;
	s[0]["XL"] = 0;
	s[0]["XS"] = 0;
	s[0]["XXL"] = 0;
	s[0]["XXS"] = 0;
	s[0]["XXXL"] = 0;
	s[0]["XXXS"] = 0;
	
	s[1]["M"] = 0;
	s[1]["L"] = 0;
	s[1]["S"] = 0;
	s[1]["XL"] = 0;
	s[1]["XS"] = 0;
	s[1]["XXL"] = 0;
	s[1]["XXS"] = 0;
	s[1]["XXXL"] = 0;
	s[1]["XXXS"] = 0;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
		s[0][a[i]]++;
	}
	
	for(i=1;i<=n;i++){
		cin >> b[i];
		s[1][b[i]]++;
	}
	
	ans = ans + abs(s[1]["XL"] - s[0]["XL"]);
	ans = ans + abs(s[1]["XXL"] - s[0]["XXL"]);
	ans = ans + abs(s[1]["XXXL"] - s[0]["XXXL"]);
	ans = ans + (abs(s[1]["L"] - s[0]["L"]) + abs(s[1]["S"] - s[0]["S"]) + abs(s[1]["M"] - s[0]["M"])) / 2;
	
	cout << ans << endl;
	
	return 0;
}