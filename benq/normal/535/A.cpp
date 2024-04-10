#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

string w[100];

int main() {
	int s;
	cin >> s;
	w[0] = "zero";
	w[1] = "one";
	w[2] = "two";
	w[3] = "three";
	w[4] = "four";
	w[5] = "five";
	w[6] = "six";
	w[7] = "seven";
	w[8] = "eight";
	w[9] = "nine";
	w[10] = "ten";
	w[11] = "eleven";
	w[12] = "twelve";
	w[13] = "thirteen";
	w[14] = "fourteen";
	w[15] = "fifteen";
	w[16] = "sixteen";
	w[17] = "seventeen";
	w[18] = "eighteen";
	w[19] = "nineteen";
	w[20] = "twenty";
	w[30] = "thirty";
	w[40] = "forty";
	w[50] = "fifty";
	w[60] = "sixty";
	w[70] = "seventy";
	w[80] = "eighty";
	w[90] = "ninety";
	if (0 <= s && s < 10) {
		cout << w[s];
	} else if (10 <= s && s < 20) {
		cout << w[s];
	} else if (s % 10 == 0) {
		cout << w[s];
	} else {
		cout << w[s-(s % 10)];
		cout << '-';
		cout << w[s % 10];
	}
	return 0;
}