#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	int ans = 0;
	for (char c:s){
		if (c <= '9'){
			int n = int(c - '0');
			if (c & 1)
				ans++;
		}
		else{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}