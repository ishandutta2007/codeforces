#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	string s, s1, s2, s3;
	cin >> s;
	int n = s.size();
	for(int i=0;i<n;i++) {
		int j = i;
		int a = j % 26;
		j /= 26;
		int b = j % 26;
		j /= 26;
		int c = j;
		s1 += 'a' + a;
		s2 += 'a' + b;
		s3 += 'a' + c;
	}
	string t1, t2, t3;
	cout << "? " << s1 << endl;
	cin >> t1;
	cout << "? " << s2 << endl;
	cin >> t2;
	cout << "? " << s3 << endl;
	cin >> t3;
	string ans(n, 87);
	for(int i=0;i<n;i++) {
		ans[(t1[i]-'a')+(t2[i]-'a')*26+(t3[i]-'a')*26*26] = s[i];
	}
	cout << "! " << ans << endl;
	
}