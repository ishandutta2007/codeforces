#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int a = 0, b = 0;
	for (char c:s)
		if (c == '1')
			a++;
		else
			b++;
	for (int i = 0; i < min(a, 1); i++)
		cout << "1";
	while(b--)
		cout << "0";
	cout << endl;
	return 0;
}