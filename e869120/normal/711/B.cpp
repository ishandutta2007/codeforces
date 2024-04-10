#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long n, x[500][500], cx, cy, sum;
bool solve() {
	for (int i = 0; i < n*n; i++) { if (x[i / n][i%n] <= 0)return false; }
	for (int i = 0; i < n; i++) { long long B = 0; for (int j = 0; j < n; j++) { B += x[i][j]; }if (B != sum)return false; }
	for (int i = 0; i < n; i++) { long long B = 0; for (int j = 0; j < n; j++) { B += x[j][i]; }if (B != sum)return false; }
	long long C1 = 0; for (int i = 0; i < n; i++) { C1 += x[i][i]; }if (C1 != sum)return false;
	long long C2 = 0; for (int i = 0; i < n; i++) { C2 += x[n - 1 - i][i]; }if (C2 != sum)return false;
	return true;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { cin >> x[i][j]; if (x[i][j] == 0) { cx = i; cy = j; } } }
	if (n == 1) { cout << "1" << endl; return 0; }
	if (cx == 0) { for (int i = 0; i < n; i++)sum += x[1][i]; }
	else { for (int i = 0; i < n; i++)sum += x[0][i]; }
	long long cnt = 0; for (int i = 0; i < n; i++)cnt += x[cx][i]; x[cx][cy] = sum - cnt;
	if (solve() == true) { cout << sum - cnt << endl; }
	else { cout << "-1" << endl; }
	return 0;
}