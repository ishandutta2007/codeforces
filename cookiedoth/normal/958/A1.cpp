/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

const int mx = 20;
char a[mx][mx], b[mx][mx], c[mx][mx];
int n, ans;

void move_to() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = c[i][j];
		}
	}
}

void same() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] != b[i][j])
				return;
		}
	}
	ans = 1;
}

void flip_hor() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[n - i - 1][j] = a[i][j];
		}
	}
	move_to();
	same();
}

void flip_ver() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[n][n - 1 - j] = a[i][j];
		}
	}
	move_to();
	same();
}

void rotate() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[j][i] = a[i][j];
		}
	}
	move_to();
	flip_hor();
}

void kek() {
	flip_hor();
	flip_ver();
	flip_hor();
	flip_ver();
}

void work() {
	kek();
	rotate();
	kek();
	rotate();
	kek();
	rotate();
	kek();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> b[i][j];
		}
	}
	work();
	if (ans == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}