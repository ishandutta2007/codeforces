#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	cout << (s+t) << endl;
	return 0;
}