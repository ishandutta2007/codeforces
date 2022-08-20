#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int n, cards[3];

void test0() {
	if (cards[0] == 0 && cards[2] == 0) return;
	if (cards[1] == 0 && cards[0] == 0) return;
	if (cards[1] >= 1 && cards[2] >= 1) {
		cout << 'B';
		return;
	} else if (cards[1] == 0 && cards[2] == 0) {
		cout << 'B';
		return;
	} else if (cards[1] >= 2 && cards[2] == 0) {
		cout << 'B';
		return;
	} else if (cards[2] >= 2 && cards[1] == 0) {
		cout << 'B';
		return;
	}
}

void test1() {
	if (cards[1] == 0 && cards[2] == 0) return;
	if (cards[1] == 0 && cards[0] == 0) return;
	
	if (cards[0] >= 1 && cards[2] >= 1) {
		cout << 'G';
		return;
	} else if (cards[0] == 0 && cards[2] == 0) {
		cout << 'G';
		return;
	} else if (cards[0] >= 2 && cards[2] == 0) {
		cout << 'G';
		return;
	} else if (cards[2] >= 2 && cards[0] == 0) {
		cout << 'G';
		return;
	}
}

void test2() {
	if (cards[1] == 0 && cards[2] == 0) return;
	if (cards[2] == 0 && cards[0] == 0) return;
	if (cards[0] >= 1 && cards[1] >= 1) {
		cout << 'R';
		return;
	} else if (cards[0] == 0 && cards[1] == 0) {
		cout << 'R';
		return;
	} else if (cards[0] >= 2 && cards[1] == 0) {
		cout << 'R';
		return;
	} else if (cards[1] >= 2 && cards[0] == 0) {
		cout << 'R';
		return;
	}
}

int main() {
	cin >> n;
	F0R(i,n) {
		char a;
		cin >> a;
		if (a == 'B') cards[0]++;
		else if (a == 'G') cards[1] ++;
		else cards[2] ++;
	}
	test0();
	test1();
	test2();
	return 0;
}