#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 2e5 + 5;
char s[MN];
int main () {
	int n;
	scanf ("%d",&n);
	vector<string> v(n);
	for (auto &au : v) {
		scanf ("%s",s);
		au = string(s);
	}
	sort(v.begin(),v.end(),[&](const string &a, const string &b) {
		int sA = 0, hA = 0, sB = 0, hB = 0;
		for (char c : a) (c == 's' ? sA : hA)++;
		for (char c : b) (c == 's' ? sB : hB)++;
		return (ll)sA * hB > (ll)sB * hA;
	});
	int cntS = 0; ll ret = 0;
	for (string a : v) for (char c : a) {
		if (c == 's') ++cntS;
		else ret += cntS;
	}
	printf ("%lld\n",ret);
    return 0;
}