
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int MAXN = 400 + 4;

int n;
string s[MAXN];

string conv(string t){
	for (int l = 0; l < t.size(); ){
		if (t[l] == 'u') {
			t.insert(l, "o");
			t.insert(l, "o");
			t.erase(l+2, 1);
		}
		else if (l+1 < t.size() && t[l] == 'k' && t[l+1] == 'h') {
			t.erase(l, 1);
			if (l)
				l--;
		}
		else
			l++;
	}
	return t;
}

bool same(string a, string b){
	return conv(a) == conv(b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		bool found = false;
		for (int j = 0; j < i && !found; j++)
			if (same(s[i], s[j]))
				found = true;
		ans += !found;
	}
	cout << ans << endl;
	return 0;
}