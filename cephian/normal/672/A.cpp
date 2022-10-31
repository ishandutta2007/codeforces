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

string s = "";

int main() {	
	for(int a = 1; s.size() < 1000; ++a) {
		int b = a;
		string t = "";
		while(b) {
			t += char('0' + b%10);
			b/=10;
		}
		reverse(t.begin(),t.end());
		s += t;
	}
	int n;
	cin >> n;
	cout << s[n-1] << "\n";

}