#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int main() {	
	string s;
	cin >> s;
	for(int i = 2; i < s.size(); ++i) {
		string str = s.substr(i-2,3);
		sort(str.begin(), str.end());
		if(str == "ABC") {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}