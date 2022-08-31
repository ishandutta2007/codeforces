/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

bool isVowel(char i);
bool isOdd(char i);

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (auto &i : s) {
		if (isVowel(i)) {
			++ans;
		} else if (isOdd(i)) {
			++ans;
		}
	}

	cout << ans << endl;
}

bool isVowel(char i) {
	return (i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u');
}

bool isOdd(char i) {
	return (i == '1' or i == '3' or i == '5' or i == '7' or i == '9');
}