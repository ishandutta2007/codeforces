#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	map <string,int> mp;
	while(n--){
		string s;
		cin >> s;
		if(mp[s] == 0)
			cout << "OK\n";
		else
			cout << s << mp[s] << endl;
		mp[s]++;
	}
}