#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
int x[10][10];
bool solve() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
			int dy[8] = { -1,0,1,1,1,0,-1,-1 };
			for (int k = 0; k < 8; k++) {
				bool OK = true;
				for (int l = 0; l < 5; l++) {
					int cx = i + dx[k] * l, cy = j + dy[k] * l;
					if (cx < 0 || cx >= 10 || cy < 0 || cy >= 10 || x[cx][cy] != 1)OK = false;
				}
				if (OK == true)return true;
			}
		}
	}
	return false;
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c; cin >> c;
			if (c == 'X')x[i][j] = 1;
			if (c == 'O')x[i][j] = 2;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (x[i][j] != 0)continue;
			x[i][j] = 1;
			if (solve() == true) { cout << "YES" << endl; return 0; }
			x[i][j] = 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}