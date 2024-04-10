#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;	cin >> s >> t;
	int n;	cin >> n;
	cout << s << " " << t << "\n";
	while (n--){
		string a, b;	cin >> a >> b;
		if (s == a)
			s = b;
		else
			t = b;
		cout << s << " " << t << "\n";
	}
	return 0;
}