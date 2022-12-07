#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

int main(){
	int n;
	string str;
	map<string, int> mp;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;
		if(mp[str]) cout << "YES\n";
		else cout << "NO\n";
		mp[str] = 1;
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}