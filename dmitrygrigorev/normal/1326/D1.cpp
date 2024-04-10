#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


vector<int> manaker(const string &s) {
    vector<int> man(s.size(), 0);
    int l = 0, r = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            man[i] = min(r - i, man[l + r - i]);
        }
        while (i + man[i] + 1 < n && i - man[i] - 1 >= 0
               && s[i + man[i] + 1] == s[i - man[i] - 1]) {
            man[i]++;
        }
        if (i + man[i] > r) {
            l = i - man[i];
            r = i + man[i];
        }
    }
    for (int i = 0; i < man.size(); ++i) {
    	man[i] = 2*man[i]+1;
    }
    return man;
}

string solve(string s) {
	int a = 0, b = 0;

	string t;
	for (int i = 0; i < 2*s.size(); ++i) {
		t += s[i%s.size()];
		t += '#';
	}

	vector<int> A = manaker(s);
	vector<int> B = manaker(t);

	//cout << s << " ======\n";
	//cout << t << endl;

	for (int i = 0; 2*(i+1) <= s.size(); ++i) {
		int len1 = (B[2*i+1]+1) / 4;
		int len2 = min((B[2*s.size() - 1]+1) / 4, i+1);
		//cout << len1 << " " << len2 << endl;
		if (len1 + len2 >= i+1 && 2*(i+1) >= a+b) {
			a = len1 + i + 1;
			b = 2*i + 2 - a;
		}
	}

	for (int i = 0; 2*i + 1 <= s.size(); ++i) {
		int len1 = (A[i] - 1)/2;
		int len2 = min((B[2*s.size() - 1]+1) / 4, i+1);
		//cout << len1 << " " << len2 << " " << 2*i+3 << endl;
		if (len1 + len2 >= i && 2*i+1 >= a+b) {
			a = len1 + i + 1;
			b = 2*i + 1 - a;
		}
	}

	string res = "";

	for (int i = 0; i < a; ++i) res += s[i];
	for (int i = 0; i < b; ++i) res += s[s.size() - b + i];
	return res;
}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int W;
	cin >> W;
	for (int kek = 0; kek < W; ++kek) {

		string s;
		cin >> s;

		string a = solve(s);
		reverse(s.begin(), s.end());
		string b = solve(s);
		reverse(b.begin(), b.end());

		if (a.size() < b.size()) a = b;
		cout << a << "\n";		

	}

}