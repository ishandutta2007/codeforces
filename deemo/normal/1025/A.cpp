#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int n, cnt[30];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	int mx = 0;
	for (char ch:s)
		mx = max(mx, ++cnt[ch - 'a']);

	if (n == 1){
		cout << "Yes\n";
	}
	else{
		if (mx == 1)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
	return 0;
}